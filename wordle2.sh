#!/bin/bash

# Ensure the number of arguments is a multiple of 4
if (( $# % 4 != 0 )); then
    echo "Error: The script expects arguments in groups of 4 (file, unused, used, hit)."
    echo "Usage: $0 <file1> <unused1> <used1> <hit1> [<file2> <unused2> <used2> <hit2> ...]"
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
    grep -vi "[$unused]" "$file" > "tmp$index"
    padded=$(printf "%15s" "$unused")
    echo "Exclude  '$padded': > $(wc -l < tmp$index)"

    # Process each character in "used"
    for char in $(echo "$used" | fold -w1); do
        grep -i -e "$char" "tmp$index" > "tmp$((index+1))"
        echo "         Searching for '$char': > $(wc -l < tmp$((index+1)))"
        mv "tmp$((index+1))" "tmp$index"  # Update the temporary file
    done

    # Filter by the "hit" character
    grep -i -e "$hit" "tmp$index" > "tmp$((index+1))"
    echo "   Now Exact match '$hit': > $(wc -l < tmp$((index+1)))"
    echo "-----"
    cat "tmp$((index+1))"
    mv "tmp$((index+1))" "tmp$index"  # Update the temporary file
done

# Read the content of the file
input=$(< tmp$index tr -d ' \n')

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
    char=$(printf \\$(printf "%o" $letter))  # Convert ASCII back to character
    echo "$char:${freq[$letter]}  "
done | sort -t : -k2,2nr | head -n7 | tr -d '\n'
echo

# Cleanup temporary files
rm tmp*
