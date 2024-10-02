#   Let's creat an array
my_array=(3600 Systems Programming is my favorite class)

#   Performing a for loop on it will produce the following result:
for i in "${my_array[@]}"; do
    echo "$i";
done

#   When using *, and the variable is quoted, 
#       instead, a single “result” will be produced, 
#       containing all the elements of the array:
for i in "${my_array[*]}"; do 
    echo "$i";
done

for index in "${!my_array[@]}"; do
    echo "$index";
done
echo

my_array=([foo]=bar [baz]=foobar)
for key in "${!my_array[@]}"; do 
    echo "$key";
done