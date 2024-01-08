set style data lines
set key right box
set grid
#set mxtics 1
#set mytics 1
#set grid xtics mxtics
#set grid ytics mytics
set xlabel "x"
set ylabel "probability"
set nologscale x
set logscale y
set yrange [1e-6:]
#set xtics 20
plot 'out/lamda1.dat' title ' lamda=1' ,'out/lamda5.dat' title ' lamda=5','out/lamda10.dat' title ' lamda=10' ,'out/lamda20.dat' title ' lamda=20','out/lamda50.dat' title ' lamda=50' #枠外にはみ出るのでlamdaのlの左にスペースを入力
