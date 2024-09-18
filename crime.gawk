# gawk -F, -f crime.gawk 100K.csv
#   1           2                 3             4               5               6
# CMPLNT_NUM, CMPLNT_FR_DT,   CMPLNT_FR_TM, CMPLNT_TO_DT,   CMPLNT_TO_TM,   RPT_DT,
# 101109527,  12/31/2015,     23:45:00,     0,              0,              12/31/2015,
# 153401121,  12/31/2015,     23:36:00,     0,              0,              12/31/2015,
#   7           8                                   9       10
# KY_CD,      OFNS_DESC,                        PD_CD,  PD_DESC,
# 113,        FORGERY,                          729,    "FORGERY,ETC., UNCLASSIFIED-FELO",
# 101,        MURDER & NON-NEGL. MANSLAUGHTER,   0,     0,
#   11                  12          13                  14      15              16
# CRM_ATPT_CPTD_CD, LAW_CAT_CD, JURIS_DESC,         BORO_NM,    ADDR_PCT_CD,    LOC_OF_OCCUR_DESC,
# COMPLETED,        FELONY,     N.Y. POLICE DEPT,   BRONX,      44,             INSIDE,
# COMPLETED,        FELONY,     N.Y. POLICE DEPT,   QUEENS,     103,            OUTSIDE,
#   17                  18          19          20          21          22              23              24
# PREM_TYP_DESC,    PARKS_NM,   HADEVELOPT, X_COORD_CD, Y_COORD_CD, Latitude,       Longitude,      Lat_Lon
# BAR/NIGHT CLUB,   0,          0,          1007314,    241257,     40.828848333,   -73.916661142,  "(40.828848333, -73.916661142)"
# 0,                0,          0,          1043991,    193406,     40.697338138,   -73.784556739,  "(40.697338138, -73.784556739)"
#!/bin/bash

{
    if (NR > 1) {  # Skip the header row
        crimeType = $8  # Get the crime type (OFNS_DESC)
        hour = +substr($3, 1, 2)  # Extract the hour from CMPLNT_FR_TM
        
        # Increment the count for the crime type and hour
        crimeCount[crimeType][hour]++
        crimeHour[hour]++
        
        # Store crime type for sorting later
        if (!(crimeType in seenCrimeTypes)) {
            crimeTypes[++crimeTypesCount] = crimeType
            seenCrimeTypes[crimeType] = 1
        }
    }
}
END {
    # Sort crime types array
    asort(crimeTypes)
    
    # Print the results sorted by crime type
    for (i = 1; i <= crimeTypesCount; i++) {
        crime = crimeTypes[i]
        total = 0
        for (hour in crimeCount[crime]) {
            total += crimeCount[crime][hour]
        }
        print "Crime Type:", crime, "Total Count:", total
        for (hour in crimeCount[crime]) {
            print "  Hour:", hour, "Count:", crimeCount[crime][hour]
        }
        print ""  # Add a blank line for better readability
    }

    for (hr = 0; hr < 24; hr++) {       # in crimeHour) {
        print "Hour of the day:", hr, " # of crimes: " crimeHour[hr]
    }
}
