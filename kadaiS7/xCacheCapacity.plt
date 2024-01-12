set style data linespoints
set key right box
set grid
set xlabel "Zipf parameter"
set ylabel "Cache hit ratio"
set logscale x
set nologscale y
set xrange [10e0:]
set yrange [0:0.7]
set ytics 0.1
plot 'out/xCacheCapacity.dat'
