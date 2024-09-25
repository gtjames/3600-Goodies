IN="bla@some.com;john@home.com"

OIFS=$IFS
IFS=';'
for x in $IN
do
    echo "> [$x]"
done
echo "$x"

string="john;is;17;years;old"
tokens=( $string )
echo ${tokens[*]}
echo ${tokens[4]}

cwd=$(pwd)
IFS='//'
tokens=( $cwd )
len=${#tokens[@]}
echo $len
echo ${tokens[@]}
echo ${tokens[len-1]}

IFS=$OIFS
