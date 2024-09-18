$3 >= age1 && $3 <= age2 && $5 = "Passenger" {
    printf "%-20s %5.1f\n", $1, $3; 
}
