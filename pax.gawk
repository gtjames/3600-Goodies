# gawk -F, -f pax.gawk Titanic.csv 
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
        print t ": Count=" type[t] ", Average Age=" avgAge;
    }
    print "Count=" totPax ", Average Age=" totAge / totPax;
}