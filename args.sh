#!/bin/bash

#   "$@" is a special variable in Bash that expands to all the positional parameters 
#       (i.e., all the command line arguments passed to the script). 
#       Each argument is treated as a separate word.
#   "$#" is a special variable in Bash that holds the count of your arguments

echo "You entered $# arguments"
# Loop through all the command line arguments
for arg in "$@"; do
    echo "Argument: $arg"
done
