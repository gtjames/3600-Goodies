#!/bin/bash

#   "$@" is a special variable in Bash that expands to all the positional parameters 
#       (i.e., all the command line arguments passed to the script). 
#       Each argument is treated as a separate word.
#   "$#" is a special variable in Bash that holds the count of your arguments

# Initialize total to 0
total=0

echo "You entered $# arguments in app $0"
# Loop through all the command line arguments
for num in "$@"; do
    # Add each argument to the total
    total=$((total + num))
    echo "Argument: $num"
done

# Print the total sum
echo "Total: $total"