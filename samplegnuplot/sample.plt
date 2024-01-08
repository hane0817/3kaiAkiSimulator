#set key 400,0.5
set grid
set xlabel "X axis"
set ylabel "Y axis"
set xrange [0:10]

set logscale x
set nologscale y
set ytics 0.2
plot 'data/a.dat' title 'A','data/b.dat' title 'B','data/c.dat' title 'C' with linespoints
#Cにデータを追加し，with linespointsをするとcのデータに線が付く