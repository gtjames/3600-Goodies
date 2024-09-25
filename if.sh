#!/bin/bash
# Common Comparison Operators in Bash

# 	•	For Numbers:
# 	•	-eq: equal to
# 	•	-ne: not equal to
# 	•	-lt: less than
# 	•	-le: less than or equal to
# 	•	-gt: greater than
# 	•	-ge: greater than or equal to
# 	•	For Strings:
# 	•	==: equal to
# 	•	!=: not equal to
# 	•	-z: string is null (empty)
# 	•	-n: string is not null (not empty)

if [ "$#" -eq 0 ]; then
    echo "$0 needs 4 parameters two numbers followed by two strings"
    exit
fi

a=$1
b=$2

if [ $a -lt $b ]; then
    echo "$a is less than $b"
else
    echo "$a is not less than $b"
fi
echo
#   compare directly with the arg params
if [ "$3" == "$4" ]; then
    echo "$3 is equal to $4"
else
    echo "$3 does not equal $4"
fi
echo
# Step 1: Prompt the user to enter a Linux command
read -p "Enter 1st Number: " x
read -p "Enter 2nd Number: " y

echo "Is 1st < 10 && 2nd > 5"
if [ $x -lt 10 ] && [ $y -gt 5 ]; then
    echo "Both conditions are true"
else
    echo "At least one condition is false"
fi
echo
echo "Is 1st < 10 || 2nd > 5"
if [ $x -lt 10 ] || [ $y -gt 5 ]; then
    echo "At lease one condition is true"
else
    echo "both are false"
fi