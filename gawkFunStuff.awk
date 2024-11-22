find a field with an '@' and print it
gawk '{ for (i=1; i<=NF; i++) if ($i ~ /@/) print $i }' names

print the 2nd field
gawk '{ print $2 }' names