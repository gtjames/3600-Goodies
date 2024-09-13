gawk '
BEGIN {
  # IFS='$'
}
{
  if (length($0) > longLine) {
    longLine = length($0)
    lineNum = NR
  }
  # Loop through each field (word) in the line
  for (i = 1; i <= NF; i++) {
    # Check for longest field
    if (length($i) > length(longest)) {
      longest = $i
      lRow = NR
    }

    # Check for shortest field
    if (length(shortest) == 0 || length($i) < length(shortest)) {
      shortest = $i
      sRow = NR
    }
  }
}

# After processing all lines, print the results
END {
  print "Long Ln: " lineNum " "  longLine
  print "Longest: " longest
  print "Length:  " length(longest)
  print "@ row #: " lRow
  print ""
  print "Shortest:" shortest
  print "Length:  " length(shortest)
  print "@ row #: " sRow
}
' $1
