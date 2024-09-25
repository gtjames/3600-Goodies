#!/bin/bash

# File to read
FILE="$1"
line_number=1
# When reading lines from a file, 
#   IFS is often set to an empty string (IFS=) to prevent Bash from splitting fields at spaces or tabs. 
#   This ensures that the entire line is read as-is without trimming spaces or breaking at whitespace.
#   In file-reading loops like while IFS= read -r line, 
#       setting IFS= ensures that each line is read as a whole, 
#       preserving whitespace, and avoiding field splitting based on the default IFS.
# Read file line by line
while IFS= read -r line; do
    printf "%-5d: %s\n" "$line_number" "$line"
    # echo "$line_number: $line"
    line_number=$((line_number + 1))

done < "$FILE"
