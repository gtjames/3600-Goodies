# find a field with an '@' and print it
gawk '{ for (i=1; i<=NF; i++) if ($i ~ /@/) print $i }' names

# print the 2nd field
gawk 'BEGIN { FS = "," }{ print $3 }' Titanic.csv