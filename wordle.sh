#!/bin/bash

# Check if both arguments are provided
if [ "$#" -ne 3 ]; then
    echo "Usage: $0 <file> <unused> <characters>"
    exit 1
fi

# Assign arguments to variables
file="$1"
unused="$2"
characters="$3"

grep -vi "[$unused]" "$file" > tmp

# Loop through each character in the list
for char in $(echo "$characters" | fold -w1); do
    echo "Searching for '$char' in '$file':"
    grep -i -e "$char" tmp > tmp
    echo "-----"
done