## Gawk `(haiku)`

Parsing with gawk's grace,  
Data streams in fields arrayed,  
Scripts dance, files embrace.

## Gawk Forevermore 
`(a poem in iambic pentameter about gawk)`

In data's realm where chaos often reigns,  
A tool called gawk emerges, clear and bright.  
With patterns, fields, and logic it maintains,  
The flow of text through scripts both day and night.

It parses lines and splits them with a charm,  
Transforming raw and cluttered, tangled streams.  
To order's call, it raises no alarm,  
Awakening the data from its dreams.

With gawk in hand, the columns yield their gold,  
From CSVs, it gleans the hidden truths.  
A treasure trove of insights to behold,  
Unveiling secrets, data's deepest roots.

So praise be gawk, the scribe of data's lore,  
A silent bard who sings forevermore.

**1\. Count the Number of Lines in a File**

`gawk 'END {print NR}' file.txt`

**2\. Sum a Column of Numbers**

`gawk -F, '{sum += $2} END {print sum}' file.csv`

**3\. Print Lines Matching a Pattern**

`gawk '/pattern/ {print}' file.txt`

**4\. Print the Last Field of Each Line**

`gawk '{print $NF}' file.txt`

**5\. Print Lines Longer than 80 Characters**

`gawk 'length($0) > 80' file.txt`

**6\. Convert a CSV File to a Tab-Delimited File**

`gawk -F, '{OFS="\\t"; print}' file.csv > file.tsv`

**7\. Print Unique Values from a Column**

`gawk -F, '!seen\[$1\]++ {print $1}' file.csv`

**8\. Find the Maximum Value in a Column (3<sup>rd</sup>)**

`gawk -F, 'NR == 1 {max = $3} $3 > max {max = $3} END {print max}' file.csv`

**9\. Print Fields in Reverse Order**

`gawk '{for(i=NF; i>0; i--) printf "%s ", $i; print ""}' file.txt`

**10\. Calculate the Average of a Column (2<sup>nd</sup>)**

`gawk -F, '{sum += $2; count++} END {print sum/count}' file.csv`

`gawk -F, '{sum += $2; count++} END {print "Sum: " sum; print "Average: " (sum/count)}' file.csv`

**Explanation:**

- \-F,: Sets the field separator to a comma (,) for reading the CSV file.
- {sum += $2; count++}: For each line, adds the value in the second column ($2) to the variable sum and increments the variable count.
- END {print "Sum: " sum; print "Average: " (sum/count)}: After processing all lines, prints the total sum and the average value of the second column.

This command will output the sum and average of the values in the second column of file.csv.

**11\. Calculate the Standard Deviation of a Column**

To calculate the standard deviation of a column in a CSV file using gawk, you need to follow a two-pass approach: first, compute the mean of the values, and then calculate the standard deviation based on the mean. Here's a gawk script to do this, assuming the CSV file is named file.csv and the column of interest is the second column.

gawk -F, '

{

\# Accumulate sum and count for calculating mean

sum += $2

sumsq += $2 \* $2

count++

}

END {

\# Calculate mean

mean = sum / count

\# Calculate variance

variance = (sumsq / count) - (mean \* mean)

\# Calculate standard deviation

stddev = sqrt(variance)

\# Print results

print "Sum: " sum

print "Mean: " mean

print "Variance: " variance

print "Standard Deviation: " stddev

}
' file.csv

**Explanation:**

- \-F,: Sets the field separator to a comma (,) for reading the CSV file.
- sum += $2: Adds the value in the second column ($2) to the variable sum.
- sumsq += $2 \* $2: Adds the square of the value in the second column to the variable sumsq for later use in variance calculation.
- count++: Increments the variable count to keep track of the number of values.
- END { ... }: After processing all lines, calculates the mean, variance, and standard deviation, then prints the results.
  - mean = sum / count: Calculates the mean of the values.
  - variance = (sumsq / count) - (mean \* mean): Calculates the variance.
  - stddev = sqrt(variance): Calculates the standard deviation using the square root of the variance.

Make sure to change $2 to the appropriate column number if you want to calculate the standard deviation for a different column.

This script will output the sum, mean, variance, and standard deviation of the values in the specified column of file.csv.

**11\. Find the longest field**

To find the longest field in a CSV file using gawk, you can write a script that keeps track of the longest field encountered as it processes each line and field. Here's an example script:

gawk -F, '

{

for (i = 1; i <= NF; i++) {

if (length($i) > max_length) {

max_length = length($i)

longest_field = $i

}

}

}

END {

print "Longest field:", longest_field

print "Length:", max_length

}' file.csv

**Explanation:**

- \-F,: Sets the field separator to a comma (,) for reading the CSV file.
- for (i = 1; i <= NF; i++): Iterates over each field in the current line.
- if (length($i) > max_length): Checks if the length of the current field ($i) is greater than max_length.
- max_length = length($i); longest_field = $i: If true, updates max_length and stores the current field in longest_field.
- END { print "Longest field:", longest_field; print "Length:", max_length }: After processing all lines, prints the longest field and its length.