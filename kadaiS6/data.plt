set style data lines
set key right box
set grid

set xlabel "contents"
set ylabel "probability"
set nologscale x
set logscale y
set yrange [:1e-0]
plot 'out/count1.dat' title ' theta=0.4' ,'out/count2.dat' title ' theta=0.6','out/count3.dat' title ' theta=0.8' ,'out/count4.dat' title ' theta=1.0','out/count5.dat' title ' theta=1.2' #枠外にはみ出るのでlamdaのlの左にスペースを入力
