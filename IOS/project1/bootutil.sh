#!/bin/bash
BOOT_ENTRIES_DIR=${BOOT_ENTRIES_DIR:-"/home/tjoslef/skola/vut/IOS/project1/loader/entries"}
echo "BOOT_ENTRIES_DIR: $BOOT_ENTRIES_DIR"
parsing_conf() {
    local file="$1"
    local by_kernel="$2"
    local by_title="$3"

    local title=$(grep "^title[[:space:]]*" "$file" | sed 's/^title[[:space:]]*//' | tail -n 1)
    local version=$(grep "^version[[:space:]]*" "$file" | sed 's/^version[[:space:]]*//' | tail -n 1)
    local linux=$(grep "^linux[[:space:]]*" "$file" | sed 's/^linux[[:space:]]*//' | tail -n 1)
    local sortKey=$(grep "^sort-key[[:space:]]*" "$file" | sed 's/^sort-key[[:space:]]*//' | tail -n 1)

    if [[ -z "$title" || -z "$version" || -z "$linux" ]]; then
        echo "Error: $file does not have all required keys (title, version, linux)" >&2
        return 1
    fi

    if [[ -n "$by_kernel" ]] && ! [[ "$linux" =~ $by_kernel ]]; then
        return 1
    fi

    if [[ -n "$by_title" ]] && ! [[ "$title" =~ $by_title ]]; then
        return 1
    fi

    echo "$file:$title ($version, $linux):$sortKey"
}
check_dir() {
    local dir="$1"
    if [[ -z "$dir" ]]; then
        echo "Error: BOOT_ENTRIES_DIR is not set." >&2
        return 1
    fi

    if [[ ! -d "$dir" ]]; then
        echo "Error: BOOT_ENTRIES_DIR '$BOOT_ENTRIES_DIR' does not exist." >&2
        return 1
    fi

    return 0
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
            :) echo "Chyba: Přepínač -$OPTARG vyžaduje argument" >&2; return 1 ;;
            \?) echo "Error : wrong input: -$OPTARG" >&2; return 1;;
        esac
    done
    if [ $# -gt $((OPTIND - 1)) ]; then
            echo "Chyba: Neočekávaný argument: ${@:$OPTIND}" >&2
            return 1
    fi
    shift $((OPTIND - 1))
    mapfile -t file_array < <(reading_dir)
    if [[ "$sort_name" = "true" ]]; then
        echo "sort_name is true"
      file_array=($(printf "%s\n" "${file_array[@]}" | sort))
    fi
    local data_array=()
    echo "TODO: Implementace příkazu list"
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
            echo "sortKey is '$sortKey'"
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
    if ! check_dir "$BOOT_ENTRIES_DIR"; then
        echo "wrong directory '$BOOT_ENTRIES_DIR'" >&2
        return 1
    fi
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
    for i in "${data_array[@]}";do
        echo "$i"
    done
    for entry in "${data_array[@]}"; do
        local filename=$(echo "$entry" | awk -F ':' '{print $1}')
        rm "$filename"
        echo "Removed file: $filename"
    done
  echo "TODO: Implementace příkazu remove"
}

duplicate_entry() {
  echo "TODO: Implementace příkazu duplicate"
}

show_default() {
  echo "TODO: Implementace příkazu show-default"
}

make_default() {
  echo "TODO: Implementace příkazu make-default"
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
  make-default)
      shift
      make_default "$@"
      ;;
  *)
      echo "Neznámý příkaz: $1"
      exit 1
      ;;
esac

exit 0
