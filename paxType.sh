#!/bin/bash

# Declare associative arrays for storing age sums and counts by class
declare -A ageSum
declare -A count

# Read the CSV file line by line
while IFS=, read -r lastName firstName age class passengerOrCrew role survivor; do
    # Skip the header line
    if [[ "$lastName" == "LastName" ]]; then
        continue
    fi
    
    # Check if age is a number
    if [[ "$age" =~ ^[0-9]+$ ]]; then
        # Add age to the total for this class and increment count
        ageSum["$class"]=$(( ${ageSum["$class"]} + age ))
        count["$class"]=$(( ${count["$class"]} + 1 ))
    fi
done < "Titanic.csv"

# Calculate and print the average age for each class
for class in "${!ageSum[@]}"; do
    avg=$(( ageSum["$class"] / count["$class"] ))
    echo "$class - Average Age: $avg"
done