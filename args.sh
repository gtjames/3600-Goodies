#!/bin/bash

#   "$@" is a special variable in Bash that expands to all the positional parameters 
#       (i.e., all the command line arguments passed to the script). 
#       Each argument is treated as a separate word.
#   "$#" is a special variable in Bash that holds the count of your arguments
# Positional Parameters
# •	$0: The name of the script or the shell.
# •	$1, $2, ...: The first, second, and subsequent arguments to the script.
# •	$@: All the arguments passed to the script, treated as separate words.
# •	$*: All the arguments passed to the script, treated as a single word.
# Special Parameters
# •	$#: The number of arguments passed to the script.
# •	$?: The exit status of the last command executed.
# •	$$: The process ID (PID) of the current shell.
# •	$!: The process ID of the last background command.
# •	$_: The last argument of the previous command.
# •	$-: The current options set for the shell.
# •	$IFS: The Internal Field Separator, which is used for word splitting.

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