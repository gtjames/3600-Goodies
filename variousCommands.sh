grep -i "\bwood\b" Titanic.csv
grep  "\bwood\b" Titanic.csv
grep -i "wood" Titanic.csv
grep -i "^BOW" Titanic.csv

grep "[a-zA-Z_][a-zA-Z_0-9]*" *.js
grep "}$" test.js       //  find lines that end with }
grep "^.....$" test.js

grep "\[a-zA-Z_][a-zA-Z_0-9]*" *.js
grep -E "\([0-9]{3}\) [0-9]{3}-[0-9]{4}" 

grep "01" dates.txt
grep "^01" dates.txt

variables in bash

name="John"
age=30
echo "Name:name"
echo "Age: $age"
echo "My name is $name and I am $age years old."
echo 'My name is $name and I am $age years old.'
current_time=$(date)
echo "Current time: $current_time"
current_dir=$(pwd)

x=$(ls)
echo $x > xx
while IFS= read -r line
do
    ls -l "$line"
done < xx

startup and shutdown
systemd

read var1 var2 var3
1 2 3 4 5 6
what is var3
echo $var
echo \$var

where is everything $PATH

Linux is multiuser / multitasking
two modes kernal and user

date;ls *.c;date

which is true
0 ^ number = number
1 | number >= number
0 & number = 0

script.sh
echo $1
echo $3 $2 $1
script a b c d e f


look at bash script control structures
Bash provides several types of control structures for decision-making, loops, and conditional execution. Here’s a quick guide to the most commonly used Bash control structures:

1. Conditional Statements (if-elif-else)

Bash uses the if statement to execute commands based on conditions.
if [ condition ]; then
    # commands if condition is true
elif [ another_condition ]; then
    # commands if another condition is true
else
    # commands if no condition is true
fi

#!/bin/bash

num=50

if [ $num -gt 10 ]; then
    echo "Number is greater than 10."
elif [ $num -eq 5 ]; then
    echo "Number is equal to 5."
else
    echo "Number is less than 10."
fi

for var in list; do
    # commands
done

#!/bin/bash

for i in 1 2 3 4 5; do
    echo "Number: $i"
done


while [ condition ]; do
    # commands
done


#!/bin/bash

count=1

while [ $count -le 5 ]; do
    echo "Count: $count"
    count=$((count + 1))
done

case $variable in
    pattern1)
        # commands for pattern1
        ;;
    pattern2)
        # commands for pattern2
        ;;
    *)
        # default commands if no pattern matches
        ;;
esac

#!/bin/bash

read -p "Enter a letter: " letter

case $letter in
    a)
        echo "You entered 'a'."
        ;;
    b)
        echo "You entered 'b'."
        ;;
    *)
        echo "You entered something else."
        ;;
esac


#!/bin/bash

greet() {
    echo "Hello, $1!"
}

greet "World"




xxxx Parameters are mapped onto secondary storage.
Parameters are passed in registers.
Parameters are pushed onto the stack by the application and popped off the stack by the operating system.

EOF is ^D

not address in a sed command means apply to all

chmod go+rx test.c      set the r and x bits for the Group and the Owner

sed -e      "s/------/  \^_\^ /" xx
sed -e "40,46s/------/  \^_\^ /" xx


sed /t_/s/sh/test/ sedfile.txt
sed /t_/\!s/sh/test/ sedfile.txt
sed -e '/rwx/=' sedfile.txt
sed -e '1,10y/rwx/ABC/' sedfile.txt


gawk
works on records and fields
$0 is the current record