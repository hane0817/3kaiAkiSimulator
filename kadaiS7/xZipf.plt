set style data linespoints
set key right box
set grid
set xlabel "Zipf parameter"
set ylabel "Cache hit ratio"
set xtics 0.1
set yrange [0.1:0.8]
set ytics 0.1
plot 'out/xZipf.dat'
