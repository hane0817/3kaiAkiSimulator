set style data lines
set key right box
set grid
#set mxtics 1
#set mytics 1
#set grid xtics mxtics
#set grid ytics mytics
set xlabel "p1"
set ylabel "average que length"

set yrange [0.005:0.05]
set xrange [0.1:0.35]
#set xtics 20
plot 'out/averageQueLength.dat'
