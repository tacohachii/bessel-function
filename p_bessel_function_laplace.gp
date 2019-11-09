set cbrange[0:1.8]
set ticslevel 0
set xrange [0:1]
set yrange [0:2]
set zrange [-1:1]
set xlabel "r"
set ylabel "f"
set zlabel "z"

set size square
plot 'd_bessel_function_laplace_m_test.dat'  using 1:4 with points title column(1)

#set size square
#plot 'd_bessel_function_laplace_m_test.dat' index 0 using 1:2:4 with points lc palette title column(1)

#set view 90,0,1,1
#set isosamples 1000000000
#set pm3d depthorder
#set view equal xyz
#splot 'd_bessel_function_laplace_m12_top.dat' using 1:2:3:($4/2) with lines lc palette title "m=12"#with pm3d title "z=1の波の様子(m=12)"

reset
