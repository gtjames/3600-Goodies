sed '=' dates.txt | sed 'N;s/\n/ /'     #   join line numbers to the line

#   match first and last character
sed -n '/^\(.\).*\1$/p' dates.txt

#   match 1st and 2nd character with the last two characters
sed -n '/^\(.\)\(.\).*\2\1$/p' dates.txt

#Put first name at the start before the sirname
sed -r "s/([A-Za-z]+),([A-Za-z ,]+)/\2 \1,/g" Titanic.csv 

#   skip lines 7-12 for the search and repalce command
sed '7,12! s/e/XXX/g' .sh
