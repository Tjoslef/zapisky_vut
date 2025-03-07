#!/bin/bash

printHelp()
{
    echo "Usage: ./main.sh [options]"
    echo "If no options are specified, the script will run all the codes"
    echo "Options:"
    echo "  -h, --help      Show this help message"
    echo "  -r, --revision  Show the comments inside codes"
    echo "  -b, --basics    Run the basic test codes ONLY"
    echo "  -s, --sizeofs   Run the sizeof codes ONLY"
    echo "  -m, --modules   Run the module codes ONLY"
    exit
}

handleOptions()
{
    # inspirace odtud
    # https://stackoverflow.com/a/29754866

    # More safety, by turning some bugs into errors.
    set -o errexit -o pipefail -o noclobber -o nounset

    # ignore errexit with `&& true`
    getopt --test > /dev/null && true
    if [[ $? -ne 4 ]]; then
        echo 'I’m sorry, `getopt --test` failed in this environment.'
        exit 1
    fi

    LONGOPTS=help,revision,basics,sizeofs,modules
    OPTIONS=hrbsm

    # -temporarily store output to be able to check for errors
    # -activate quoting/enhanced mode (e.g. by writing out “--options”)
    # -pass arguments only via   -- "$@"   to separate them correctly
    # -if getopt fails, it complains itself to stdout
    PARSED=$(getopt --options=$OPTIONS --longoptions=$LONGOPTS --name "$0" -- "$@") || exit 2
    # read getopt’s output this way to handle the quoting right:
    eval set -- "$PARSED"

    while true; do
        case "$1" in
            -h|--help)
                printHelp
                shift
                ;;
            -r|--revision)
                revision=true
                shift
                ;;
            -b|--basics)
                all=false
                basic_test_codes=true
                shift
                ;;
            -s|--sizeofs)
                all=false
                sizeof_codes=true
                shift
                ;;
            -m|--modules)
                all=false
                module_codes=true
                shift
                ;;
            --)
                shift
                break
                ;;
            *)
                echo "$0: invalid option -- '$1'"
                break
                ;;
        esac
    done
}

printLineAcrossTerminal()
{
    printf '%*s\n' "${COLUMNS:-$(tput cols)}" '' | tr ' ' -
}

printInstructions()
{
    printLineAcrossTerminal
    echo "Piš odpovědi přesně, tzn. 4 != '4' != \"4\""
    echo "Pokud funkce vrací int, ale ty dostaneš char, tak je lepší napsat 'D' místo 68"
    echo "V případě nedefinovaného chování napiš \"undef\""
    echo "V případě, že se kód nedá přeložit napiš \"compile\""
    echo "V případě, že je výsledek \0, tak napiš \"null byte\""
    printLineAcrossTerminal
}

installBatcat()
{
    declare -A pkg_managers=(
        ["apt-get"]="sudo apt-get install bat -y" # UBUNTU/DEBIAN
        ["apk"]="apk add bat" # ALPINE
        ["pacman"]="pacman -S bat" # ARCH
        ["dnf"]="dnf install bat" # FEDORA
        ["emerge"]="emerge sys-apps/bat" # GENTOO/FUNTOO
        ["xbps-install"]="xbps-install -S bat" # VOID LINUX
        ["pkg"]="pkg install bat" # FREEBSD/TERMUX
        ["pkg_add"]="pkg_add bat" # OPENBSD
        ["nix-env"]="nix-env -i bat" # NIXOS
        ["zypper"]="zypper install bat" # OPEN SUSE
    )

    if ! command -v bat &> /dev/null || ! command -v batcat &> /dev/null; then
        for pkg_manager in "${!pkg_managers[@]}"; do
            if command -v $pkg_manager &> /dev/null; then
                ${pkg_managers[$pkg_manager]} && break
            fi
        done
    fi
}

compileCodes()
{
    cd $1
    make &> /dev/null
    cd ..
}

printScore()
{
    local correct=$1
    local n_of_codes=$2

    if [ $correct -eq $n_of_codes ]; then
        echo -e "🎉 \e[32mAll passed\e[0m 🎉"
    else
        echo "Score: $correct/$n_of_codes"
    fi
    printLineAcrossTerminal
}

all=true
revision=false
basic_test_codes=false
sizeof_codes=false
module_codes=false

handleOptions "$@"
installBatcat
printInstructions

if grep -q 'ID=ubuntu\|ID=debian' /etc/os-release &> /dev/null; then
    bat_cmd='batcat'
else
    bat_cmd='bat'
fi

correct=0
n_of_codes=0

# basic test codes
if [ "$all" == true ] || [ "$basic_test_codes" == true ]; then
    compileCodes "./test_codes"

    for file in ./test_codes/*.c; do
        n_of_codes=$((n_of_codes+1))

        file_name_with_extension=$(basename $file)
        file_name_no_extension="${file_name_with_extension%.c}"

        if [ "$revision" == "true" ]; then
            cat $file | sed -n "/startPrint/,/stopPrint/p" | sed '1d;$d' | $bat_cmd -pfl c
        else
            awk '/\/\/ startPrint/{flag=1;next} flag && /\/\// {print $0; exit}' $file | $bat_cmd -pfl c
            awk '/\/\/ startPrint/,/\/\/ stopPrint/{ if ($0 !~ /\/\// || NR == 1) print $0 }' $file | $bat_cmd -pfl c
        fi

        read -p "> " input

        if [ -f "./test_codes/$file_name_no_extension" ]; then
            result=$(./test_codes/$file_name_no_extension)
        else
            result="compile"
        fi

        if [ "$input" == "$result" ]; then
            echo -e "\n\e[32mCorrect\e[0m\n"
            correct=$((correct+1))
        else
            echo -e "\n\e[31mIncorrect, the correct answer was \e[0m\e[34m$result\e[0m\n"
        fi
    done

    printScore $correct $n_of_codes
fi

# sizeof codes
if [ "$all" == true ] || [ "$sizeof_codes" == true ]; then
    compileCodes "./sizeof_codes"

    for file in ./sizeof_codes/*.c; do
        n_of_codes=$((n_of_codes+1))

        file_name_with_extension=$(basename $file)
        file_name_no_extension="${file_name_with_extension%.c}"

        if [ "$revision" == "true" ]; then
            cat $file | sed -n "/startPrint/,/stopPrint/p" | sed '1d;$d' | $bat_cmd -pfl c
        else
            awk '/\/\/ startPrint/{flag=1;next} flag && /\/\// {print $0; exit}' $file | $bat_cmd -pfl c
            awk '/\/\/ startPrint/,/\/\/ stopPrint/{ if ($0 !~ /\/\// || NR == 1) print $0 }' $file | $bat_cmd -pfl c
        fi

        read -p "> " input
        input=$(echo $input | tr -d " ")

        result=$(./sizeof_codes/$file_name_no_extension | tr -d " ")

        IFS=';' read -ra results <<< "$result"

        bool_correct=false
        for result in "${results[@]}"; do
            if [ "$result" == "$input" ]; then
                echo -e "\n\e[32mCorrect\e[0m\n"
                bool_correct=true
                correct=$((correct+1))
                break
            fi
        done
        if [ "$bool_correct" == false ]; then
            echo -e "\n\e[31mIncorrect, the correct answer was for example \e[0m\e[34m$result\e[0m\n"
        fi
    done

    printScore $correct $n_of_codes
fi

# module codes
if [ "$all" == true ] || [ "$module_codes" == true ]; then
    compileCodes "./module_codes"

    for module in $(ls ./module_codes/*.c | sed -r 's/.*\/(module[[:alnum:]]).*/\1/' | sort -u); do
        n_of_codes=$((n_of_codes+1))
        echo "Co vrátí funkce main()?"

        for file in ./module_codes/${module}*.c; do
            file_name_with_extension=$(basename $file)
            file_name_no_extension="${file_name_with_extension%.c}"

            if [ "$revision" == "true" ]; then
                cat $file | sed -n "/startPrint/,/stopPrint/p" | sed '1d;$d' | $bat_cmd -fl c --file-name $file
            else
                awk '/\/\/ startPrint/,/\/\/ stopPrint/ { if (!/\/\//) print }' $file | $bat_cmd -fl c --file-name $file
            fi
        done

        read -p "> " input

        if [ -f "./module_codes/$module" ]; then
            result=$(./module_codes/$module)
        else
            result="compile"
        fi

        if [ "$input" == "$result" ]; then
            echo -e "\n\e[32mCorrect\e[0m\n"
            correct=$((correct+1))
        else
            echo -e "\n\e[31mIncorrect, the correct answer was \e[0m\e[34m$result\e[0m\n"
        fi
    done

    printScore $correct $n_of_codes
fi
