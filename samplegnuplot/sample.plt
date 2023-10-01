set data style linespoints
set key 400,0.5
set grid
set xlabel "X axis"
set ylabel "Y axis"
set logscale x
set nologscale y
set ytics 0.2
plot 'data/a.dat' title 'A','data/b.dat' title 'B','data/c.dat' title 'C'