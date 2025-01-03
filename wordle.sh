#!/bin/bash

# Ensure the number of arguments is a multiple of 3
if (( $# % 4 != 0 )); then
    echo "Error: The script expects arguments in groups of 3 (characters, file, description)."
    echo "Usage: $0 <chars1> <file1> <desc1> [<chars2> <file2> <desc2> ...]"
    exit 1
fi

# Process the arguments in groups of 4
index=0

for (( i=1; i<=$#; i+=4 )); do
    echo "Loop '$i' of '$#'"
    # Extract the current group of arguments
    file=$(eval echo \${$i})
    unused=$(eval echo \${$((i+1))})
    used=$(eval echo \${$((i+2))})
    hit=$(eval echo \${$((i+3))})

    # Filter out lines containing characters in "unused"
    grep -vi "[$unused]" "$file" > tmp$((index))
    padded=$(printf "%15s" "$unused")
    echo "Exclude  '$padded': > $(wc -l tmp$((index)))"

    # Loop through each character in the list
    for char in $(echo "$used" | fold -w1); do
        grep -i -e "$char" tmp"$((index))" > tmp$((index+1))
        echo "         Searching for '$char': > $(wc -l tmp$((index+1)))"
        ((index++))  # Increment the index
    done

    # Filter by the "hit" character
    grep -i -e "$hit" tmp$((index)) > tmp$((index+1))
    echo "   Now Exact match '$hit': > $(wc -l tmp$((index+1)))"
    echo "-----"
    cat tmp$((index+1))
done

# Read the content of the file
input=$(cat "tmp$((index+1))" | tr -d ' \n')

# Initialize an associative array to store letter counts
declare -A freq

# Count each letter
for ((i = 0; i < ${#input}; i++)); do
    char="${input:i:1}" # Extract a single character
    char_ascii=$(printf "%d" "'$char'")  # Get ASCII value
    ((freq["$char_ascii"]++)) # Increment count
done

# Print the frequencies in descending order
echo "Letter frequencies (most to least):"
for letter in "${!freq[@]}"; do
    char=printf \\$(printf "%o" $letter)  # Convert ASCII back to character
    echo "$char:${freq[$letter]}  "
done | sort -t : -k2,2nr | head -n5 | tr -d '\n'
echo

# Cleanup temporary files
rm tmp*