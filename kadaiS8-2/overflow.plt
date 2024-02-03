set style data linespoints
set key right box
set grid
#set mxtics 1
#set mytics 1
#set grid xtics mxtics
#set grid ytics mytics
set xlabel "p1"
set ylabel "overflow probability"

set yrange [0:0.05]
set xrange [0.1:0.35]
set ytics 0.005
plot 'out/overflow.dat'
