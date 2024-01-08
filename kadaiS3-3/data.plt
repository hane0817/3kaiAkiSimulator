set style data linespoints
set grid
set xlabel "k axis"
set ylabel "p axis"
set xrange [0:20]
set yrange [0:0.5]
set xtics 5
set ytics 0.05
plot '../kadaiS2/out/out.dat' title 'analysis', 'out/N=10.dat' title 'simulation(N=10)'  ,'out/N=1000.dat' title 'simulation(N=1000)','out/N=100000.dat' title 'simulation(N=100000)' 