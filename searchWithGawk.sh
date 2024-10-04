#!/bin/bash
if [ "$#" -lt 2 ]; then
    echo "$0 needs 2 parameters <search pattern> <file to search>"
    exit
fi

# Assign the first command-line argument to a variable
pattern="$1"

# Use the shell variable inside the gawk command
cat $2 | gawk -v pattern="$1" '{ if ($1 ~ pattern) { print $1 " matches pattern! " pattern } }'
