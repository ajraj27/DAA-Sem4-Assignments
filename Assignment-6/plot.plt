set terminal png size 600,500
set output "A6graph.png"
set title "time Complexity"
set xlabel "degree of polynomial"
set ylabel "computation time"
plot "graph.dat" with lines title "average case"
