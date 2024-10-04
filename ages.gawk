#       gawk -v age1=33 -v age2=34 -F, -f ages.gawk Titanic.csv

$3 >= age1 && $3 <= age2 && $5 = "Passenger" {
    printf "%10.10s\n%-20s %5.1f\n", $0, $1, $3; 
}
END {
    printf "That's all folks\n";
}