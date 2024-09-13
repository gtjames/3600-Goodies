#!/bin/bash

# Check if the bucket size argument is provided
if [ -z "$1" ]; then
    echo "Usage: $0 <bucket_size>"
    exit 1
fi

# Bucket size is the first argument
bucket_size=$1

# Run gawk with the provided bucket size
gawk -v bucket="$bucket_size" -F, '
{
    if ($3 != "" && $3 ~ /^[0-9]+(\.[0-9]+)?$/) {
        age_group = int($3 / bucket) * bucket
        count[age_group]++
    }
}
END {
    for (age in count) {
        print age, count[age]
    }
}
' Titanic.csv > ages.dat

echo "Age buckets calculated and saved to age_buckets.dat"

gnuplot -c ages.plot