#!/bin/bash

# Create temporary files to store counts and age sums for each class
countFile=$(mktemp)
ageFile=$(mktemp)

# Read the CSV file line by line
while IFS=',' read -r lastName firstName age class passengerType role survivor; do
    # Skip the header and crew members (we only want passengers)
    if [[ "$lastName" != "LastName" && "$passengerType" == "Passenger" ]]; then
        # Update the count for the passenger class
        count=$(grep -c "^$class$" "$countFile")
        if [[ $count -eq 0 ]]; then
            echo "$class" >> "$countFile"
            echo "$class:1" >> "$ageFile"
            echo "$class:$age" >> "$ageFile"
        else
            currentCount=$(grep "^$class:" "$ageFile" | cut -d':' -f2)
            newCount=$((currentCount + 1))
            sed -i "s/^$class:.*/$class:$newCount/" "$ageFile"

            currentAge=$(grep "^$class:" "$ageFile" | tail -1 | cut -d':' -f3)
            newAge=$(echo "$currentAge + $age" | bc)
            sed -i "s/^$class:$currentCount:.*/$class:$newCount:$newAge/" "$ageFile"
        fi
    fi
done < Titanic.csv

# Calculate and print the results
while read -r line; do
    passengerClass=$(echo "$line" | cut -d':' -f1)
    count=$(echo "$line" | cut -d':' -f2)
    totalAge=$(echo "$line" | cut -d':' -f3)
    avgAge=$(echo "scale=2; $totalAge / $count" | bc)
    echo "$passengerClass: Count=$count, Average Age=$avgAge"
done < "$ageFile"

# Clean up temporary files
rm "$countFile" "$ageFile"