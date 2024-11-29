# gawk -F, -f pax.gawk Titanic.csv 
BEGIN {
    printf "%-20s %-8s %10s\n", "Class", "Count", "Average";
}
{
    if (NR > 1) {
        type[$4]++;
        ageSum[$4] += $3;
        totAge += $3;
        totPax++;
    }
}
END {
    for (t in type) {
        avgAge = ageSum[t] / type[t];
        printf "%-20s %6d  %.2f\n", t, type[t], avgAge;
    }
    print "Count=" totPax ", Average Age=" totAge / totPax;
}