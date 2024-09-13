IFS="$1"
echo $Blue this example uses a single quote
read -r first second third <<< 'ap:ple,ban$ana,or:ange'
echo "$Green \t First: $first, Second: $second, Third: $third"
echo $Blue Watch the change when we use double quotes
read -r first second third <<< "ap:ple,ban$ana,or:ange"
echo "\t $Cyan First: $first, Second: $second, Third: $third"
#	Use single quotes (') when you want to prevent any form of shell expansion, 
#   the shell treats everything as literal text, 
##      including handling of special characters like $, \, and !.
##      no variable expansion, backslash interpretation, or other special shell processing happens.
#	Use double quotes (") when you want to allow variable expansion, 
##      command substitution, or escape sequences.