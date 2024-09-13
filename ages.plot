set terminal png size 800,600
set output 'ages.png'
set title "Titanic Passengers by Age Group"
set xlabel "Age Group (X-year intervals)"
set ylabel "Number of Passengers"
set boxwidth 4
set style fill pattern 4
plot "ages.dat" using 1:2 with boxes title "Passengers"

# Pattern 1: Solid fill.
# Pattern 2: Horizontal lines.
# Pattern 3: Vertical lines.
# Pattern 4: Diagonal lines (upwards).
# Pattern 5: Diagonal lines (downwards).
# Pattern 6: Crosshatch (both diagonal directions).