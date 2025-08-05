#!/bin/bash

file1="$1"
file2="$2"

if [[ ! -f "$file1" || ! -f "$file2" ]]; then
    echo "Usage: $0 fichier1 fichier2"
    exit 1
fi

line_num=1

paste -d'\t' "$file1" "$file2" | while IFS=$'\t' read -r line1 line2; do
    if [[ "$line1" != "$line2" ]]; then
        echo "🟥 Différence à la ligne $line_num :"
        echo "Fichier 1 : $line1"
        echo "Fichier 2 : $line2"

        # Détecte et marque les différences caractère par caractère
        max_len=$(( ${#line1} > ${#line2} ? ${#line1} : ${#line2} ))
        marker=""
        for (( i=0; i<max_len; i++ )); do
            c1="${line1:i:1}"
            c2="${line2:i:1}"
            if [[ "$c1" != "$c2" ]]; then
                marker+="^"
            else
                marker+="_"
            fi
        done
        echo "            $marker"
        echo
    fi
    ((line_num++))
done

