#!/bin/bash

# Ensure you skip the header and read the file.
awk -F, 'NR > 1 { 
    ageSum[$4] += $3; 
    count[$4]++ 
} 
END { 
    for (class in ageSum) {
        avg = ageSum[class] / count[class];
        printf "%-20s - Ave Age: %.2f\n", class, avg;
    }
}' Titanic.csv
