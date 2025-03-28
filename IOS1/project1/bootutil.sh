#!/bin/bash
#default address
BOOT_ENTRIES_DIR=${BOOT_ENTRIES_DIR:-"loader/entries"}
parsing_conf() {
    local file="$1"
    local by_kernel="$2"
    local by_title="$3"
    local num_vit="$4"
    local title=$(grep "^title[[:space:]]*" "$file" | sed 's/^title[[:space:]]*//' | tail -n 1)
    local version=$(grep "^version[[:space:]]*" "$file" | sed 's/^version[[:space:]]*//' | tail -n 1)
    local linux=$(grep "^linux[[:space:]]*" "$file" | sed 's/^linux[[:space:]]*//' | tail -n 1)
    local sortKey=$(grep "^sort-key[[:space:]]*" "$file" | sed 's/^sort-key[[:space:]]*//' | tail -n 1)
    local vut_default=$(grep "^vutfit_default[[:space:]]*" "$file" | sed 's/^vutfit_default[[:space:]]*//' | tail -n 1)
    if [[ -n "$by_kernel" ]] && ! [[ "$linux" =~ $by_kernel ]]; then
        return 1
    fi

    if [[ -n "$by_title" ]] && ! [[ "$title" =~ $by_title ]]; then
        return 1
    fi
    if [[ "$vut_default" == "y" ]]; then
        num_vit=$((num_vit + 1))
    fi
    if [[ -z "$title" || -z "$version" || -z "$linux" ]]; then
        echo "Error: $file does not have all required keys (title, version, linux)" >&2
        return 1
    fi
    echo "$file:$title ($version, $linux):$sortKey"
}
check_dir() {
    if [[ -z "$BOOT_ENTRIES_DIR" ]]; then
        echo "Error: BOOT_ENTRIES_DIR is not defined" >&2
        return 1
    fi

    if [[ ! -d "$BOOT_ENTRIES_DIR" ]]; then
        echo "the directory doenst exist: $BOOT_ENTRIES_DIR"
    fi
}
list_entries() {
    local sort_name=false
    local sort_key=false
    local by_kernel=""
    local by_title=""
    while getopts ":sfk:t:" opt; do
        case $opt in
            f) sort_name=true ;;
            s) sort_key=true ;;
            k) by_kernel="$OPTARG" ;;
            t) by_title="$OPTARG" ;;
            :) echo "chyba: přepínač -$optarg vyžaduje argument" >&2; return 1 ;;
            \?) echo "error : wrong input: -$optarg" >&2; return 1;;
        esac
    done
    if [ $# -gt $((OPTIND - 1)) ]; then
            echo "Chyba: Neočekávaný argument: ${@:$OPTIND}" >&2
            return 1
    fi
    shift $((OPTIND - 1))
    mapfile -t file_array < <(reading_dir)
    if [[ "$sort_name" = "true" ]]; then
      file_array=($(printf "%s\n" "${file_array[@]}" | sort))
    fi
    local data_array=()
    for i in "${file_array[@]}";do
        if [[ -e "$i" ]]; then
            local result=$(parsing_conf "$i" "$by_kernel" "$by_title")
            if [[ $? -ne 0 ]]; then
                echo "error in parsing_func">&2
            else
                data_array+=("$result")
            fi
        else
            echo "something goes wrong with '$i'" >&2
        fi
    done
    if [[ "$sort_key" = "true" ]]; then
        local tmp_array=()
        for entry in "${data_array[@]}";do
            local sortKey=$(echo "$entry" | awk -F ':' '{print $NF}')
            local filename=$(echo "$entry" | awk -F ':' '{print $1}')
            if [[ -z $sortKey ]];then
                local sort_key="zzz:$(basename "$filename")"
            else
                local sort_key="$sortKey"
            fi
            tmp_array+=("$sort_key|$entry")

        done
        IFS=$'\n' sorted=($(printf "%s\n" "${tmp_array[@]}" | sort -t '|' -k1,1))
        data_array=()
        for item in "${sorted[@]}";do
            data_array+=("${item#*|}")
        done
        for i in "${data_array[@]}";do
            if [[ -n "$i" ]];then
                entry="${i#*:}"
                entry="${entry%:*}"
                echo "$entry"
            fi
        done
        return 0
    fi
        for i in "${data_array[@]}";do
            if [[ -n "$i" ]];then
                entry="${i#*:}"
                entry="${entry%:*}"
                echo "$entry"
            fi
        done
    return 0
}
reading_dir(){
    check_dir "$BOOT_ENTRIES_DIR"
    local file_array=()
    for i in "$BOOT_ENTRIES_DIR"/*.conf;do
        if [[ -e "$i" ]]; then
            file_array+=("$i")
        else
            echo "error in reading dir"
            return 1
        fi
    done
    if [ ${#file_array[@]} -eq 0 ]; then
            echo "No .conf files found in $BOOT_ENTRIES_DIR." >&2
            return 1
        fi
    printf '%s\n' "${file_array[@]}"
}
remove_entry() {
    local by_title="$1"
    mapfile -t file_array < <(reading_dir)
    for i in "${file_array[@]}";do
        if [[ -e "$i" ]]; then
            local result=$(parsing_conf "$i" "$by_kernel" "$by_title")
            if [[ $? -ne 0 ]]; then
                echo "error in parsing_func">&2
            else
                data_array+=("$result")
            fi
        else
            echo "something goes wrong with '$i'" >&2
        fi
    done
    for entry in "${data_array[@]}"; do
        if [[ -n "$entry" ]];then
            local filename=$(echo "$entry" | awk -F ':' '{print $1}')
            echo "$filename"
            rm "$filename"
            echo "Removed file: $filename"
        fi
    done
}
kernel_cmd() {
    local orig_cmd="$1"
    local mod="$2"
    local params_to_add="${4:-}"
    IFS=' ' read -ra orig_params <<< "$orig_cmd"
    IFS=' ' read -ra new_params <<< "$params_to_add"

    if [[ "$mod" = 1 ]]; then
        for par in "${new_params[@]}"; do
            echo "$par"
            found=false
            for existing in "${orig_params[@]}"; do
                if [[ "$existing" == "$par" ]]; then
                    found=true
                    break
                fi
            done
            if [ "$found" = false ]; then
                orig_params+=("$par")
            fi
        done
    fi
    if [[ "$mod" = 2 ]];then
        for par in "${new_params[@]}";do
            local filtered_params=()
            for existing in "${orig_params[@]}";do
                if [[ "$existing" == "$par" || "$existing" == "$par"=* ]]; then
                   continue
                fi
            filtered_params+=("$existing")
            done
            orig_params=("${filtered_params[@]}")
        done
    fi
    echo "${orig_params[*]}"
}

duplicate_entry() {
    local by_kernel="" by_title="" by_initrd="" destination=""
    local cmdline_add="" cmdline_remove="" file=""
    local operation=()
    local last_arg="${@: -1}"
    echo "$last_arg"
    if [[ $# -gt 0 && "$last_arg" != -* && -f "$last_arg" ]]; then
        file="$last_arg"
        set -- "${@:1:$#-1}"
    fi
    while [[ $# -gt 0 ]]; do
        case "$1" in
            --make-default)
                operation+=("make_default")
                echo "make_default"
                shift 1
                ;;
            -k)
                operation+=("kernel $2")
                shift 2
                ;;
            -t)
                operation+=("title $2")
                shift 2
                ;;
            -i)
                operation+=("initrd $2")
                shift 2
                ;;
            -d)
                destination="$2"
                shift 2
                ;;
            -a)
                operation+=("cmdline_add $2")
                shift 2
                ;;
            -r)
                operation+=("cmdline_remove $2")
                shift 2
                ;;
            *)
                echo "Invalid option: $1" >&2
                return 1
                ;;
        esac
    done
    if [[ -z "$file" ]]; then
        mapfile -t file_array < <(reading_dir)
        if [[ ${#file_array[@]} -eq 0 ]]; then
            echo "Chyba: Žádné soubory nenalezeny." >&2
            return 1
        fi

        default_found=false
        for i in "${file_array[@]}"; do
            if [[ ! -f "$i" ]]; then
                echo "Varování: '$i' není soubor. Přeskočeno." >&2
                continue
            fi
            vut_default=$(awk '/^vutfit_default[[:space:]]+/ {print $2; exit}' "$i")
            if [[ "$vut_default" == "y" ]]; then
                default_found=true
                file="$i"
                break
            fi
        done
        if ! $default_found; then
            echo "Varování: Žádný výchozí soubor nebyl nalezen." >&2
            return 1
        fi
    fi

    if [[ ! -f "$file" ]]; then
        echo "Chyba: Soubor '$file' neexistuje nebo není regulérní soubor." >&2
        return 1
    fi
    original_file="$file"
    new_file="${file%.*}1.${file##*.}"
    cp "$original_file" "$new_file"
    : "${destination:="$new_file"}"
    if [[ ! -f "$destination" ]]; then
        touch "$destination"
    fi
    local content modified_content

    content=$(<"$new_file")
    modified_content="$content"
    for op in "${operation[@]}";do
        case $op in
            kernel*)
                local kernel_version="${op#kernel }"
                modified_content=$(sed "s/^\(linux[[:space:]]\+\).*/\1$kernel_version/" <<< "$modified_content")
                ;;
            title*)
                local new_title="${op#title }"
                modified_content=$(sed "s/^\(title[[:space:]]\+\).*/\1$new_title/" <<< "$modified_content")
                ;;
            initrd*)
                local new_initrd="${op#initrd }"
                modified_content=$(sed "s/^\(initrd[[:space:]]\+\).*/\1$new_initrd/" <<< "$modified_content")
                ;;
            cmdline_add*)
                local cmdline_add="${op}"
                local origin_cmd=$(awk '/^options[[:space:]]+/ {$1=""; print substr($0,2)}' <<< "$modified_content")
                local new_cmd=$(kernel_cmd "$origin_cmd" 1 "$cmdline_add")
                echo "$new_cmd"
                modified_content=$(sed "s/^options.*/options $new_cmd/" <<< "$modified_content")
                ;;
            cmdline_remove*)
                local cmdline_remove="${op}"
                local origin_cmd=$(awk '/^options[[:space:]]+/ {$1=""; print substr($0,2)}' <<< "$modified_content")
                local new_cmd=$(kernel_cmd "$origin_cmd" 2 "$cmdline_remove")
                modified_content=$(sed "s/^options.*/options $new_cmd/" <<< "$modified_content")
                ;;
               esac

           done
    echo "$modified_content" > "$destination"
    if [[ " ${operation[*]} " =~ " make_default " ]]; then
        make_default "$destination"
    fi

}

show_default() {
    local local_f_par=false
    local by_kernel=""
    local by_title=""
    local num_vit=0
    mapfile -t file_array < <(reading_dir)
    while getopts ":f" opt; do
        case $opt in
            f) local_f_par=true ;;
            :) echo "chyba: přepínač -$optarg vyžaduje argument" >&2; return 1 ;;
            \?) echo "error : wrong input: -$optarg" >&2; return 1;;
        esac
    done
    if [ $# -gt $((OPTIND - 1)) ]; then
            echo "Chyba: Neočekávaný argument: ${@:$OPTIND}" >&2
            return 1
    fi
    shift $((OPTIND - 1))
    for i in "${file_array[@]}"; do
       if [[ -e "$i" ]]; then
         local vut_default=$(grep -m 1 "^vutfit_default[[:space:]]*" "$i" | sed 's/^vutfit_default[[:space:]]*//')
         if [[ "$vut_default" == "y" ]]; then
           default_found=true
           default_file="$i"
           break
         fi
       else
         echo "Chyba: Soubor '$i' neexistuje." >&2
         return 1
       fi
     done
     if "$default_found"; then
         if "$local_f_par"; then
           echo "$default_file"
         else
           cat "$default_file"
         fi
         return 0
    else
        echo "Chyba: Žádná výchozí položka nebyla nalezena." >&2
        return 1
    fi
}
make_default() {
    local file="$1"
    if [[ -z "$file" ]]; then
        echo "Chyba: Je nutné zadat cestu k souboru." >&2
        return 1
    fi
    if [[ -f "$file" && -s "$file" ]]; then
        if grep -q '^vutfit_default\s' "$file"; then
            sed -i 's/^vutfit_default\s.*/vutfit_default y/' "$file"
            echo "zapsano do toho $file"
        else
            echo "vutfit_default y" >> "$file"
            echo "zapsano do toho $file"
        fi
    else
        echo "creating file"
        > "$file"
        for i in {1..5}; do
            echo >> "$file"
        done
        echo "vutfit_default y" >> "$file"
    fi
    if ! grep -q '^vutfit_default y' "$file"; then
        echo "Chyba: Nastavení výchozí položky selhalo" >&2
        return 1
    fi
    mapfile -t file_array < <(reading_dir)
    for i in "${file_array[@]}"; do
        if [[ "$(basename "$i")" == "$(basename "$file")" ]]; then
                echo "Skipping matching file: $i"
                continue
        fi
       if [[ -e "$i" ]]; then
           vut_default=$(awk '/^vutfit_default[ \t]/ {print $2; exit}' "$i")
         if [[ "$vut_default" == "y" ]]; then
             echo "hello $i"
           sed -i 's/^vutfit_default\s.*/vutfit_default n/' "$i"
           default_found=true
           break
         fi
       else
         echo "Chyba: Soubor '$i' neexistuje." >&2
         return 1
       fi
     done
    echo "Výchozí položka byla úspěšně nastavena v souboru $file"
}
default_dir() {
    local directory="$1"
    echo "$directory"
    local path_to_dir=$(realpath -m "$directory" 2>/dev/null)
    if [[ -z "$path_to_dir" ]]; then
        echo "Error: Directory not specified" >&2
        return 1
    fi

    if [[ ! -d "$path_to_dir" ]]; then
        if ! mkdir -p "$path_to_dir"; then
            echo "Error: Failed to create directory '$directory'" >&2
            return 1
        fi
        echo "Directory created: $path_to_dir"
    fi
    echo "$path_to_dir"
    BOOT_ENTRIES_DIR="$path_to_dir"
    echo "new directory $BOOT_ENTRIES_DIR"
}

# Hlavní logika pro parsování argumentů
case "$1" in
  list)
      shift
      list_entries "$@"
      ;;
  remove)
      shift
      remove_entry "$@"
      ;;
  duplicate)
      shift
      duplicate_entry "$@"
      ;;
  show-default)
      shift
      show_default "$@"
      ;;
  --make-default)
      shift
      make_default "$@"
      ;;
  -b)
      shift
      default_dir "$@"
      ;;
  *)
      echo "Neznámý příkaz: $1"
      exit 1
      ;;
esac

exit 0
