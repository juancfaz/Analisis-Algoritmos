Ejecutar el programa 3 pasos.

1. Abrir la terminal.
2. Ir a la carpeta sorting.
3. Ejecutar el comando make -f Makefile

Con estos pasos se creará un archivo en la carpeta /build llamado main (no tiene extension). Para ejecutarlo haremos doble clic sobre él.

Generar Datos 2 pasos.

1. Abrir la terminal en la carpeta /build donde se genero nuestro ejecutable.
2. Ejecutar el comando ./main > datos.txt

Se creará un archivo de texto en la carpeta /build que después utilizaremos.

Gráficar 4 pasos.

Requisitos:
	1. Tener instalado gnuplot.
	http://www.gnuplot.info/download.html

1. Abrir la terminal en nuestra carpeta /build donde se generaron los archivos anteriores.
2. Ejecutar el comando gnuplot.
3. Imprimimos las funciones.

set title "All Sort Methods"
set xlabel "Número de elementos"
set ylabel "Tiempo de ejecución"
plot 'datos.txt' using 1:2 with lines title 'insertSortbest*1000' smooth bezier, \
     'datos.txt' using 1:3 with lines title 'insertSortaverage' smooth bezier, \
     'datos.txt' using 1:4 with lines title 'insertSortworst' smooth bezier, \
     'datos.txt' using 1:5 with lines title 'selectionSortbest' smooth bezier, \
     'datos.txt' using 1:6 with lines title 'selectionSortaverage' smooth bezier, \
     'datos.txt' using 1:7 with lines title 'selectionSortworst' smooth bezier, \
     'datos.txt' using 1:8 with lines title 'mergeSortbest' smooth bezier, \
     'datos.txt' using 1:9 with lines title 'mergeSortaverage' smooth bezier, \
     'datos.txt' using 1:10 with lines title 'mergeSortworst' smooth bezier

También podemos imprimir solo las de un método de ordenamiento. Pero para esto tenemos que cerrar la terminal y volver a iniciar gnuplot.

Ej.

Solo inserción.

set title "Insertion Sort"
set xlabel "Número de elementos"
set ylabel "Tiempo de ejecución"
plot 'datos.txt' using 1:2 with lines title 'insertSortbest*1000' smooth csplines, \
     'datos.txt' using 1:3 with lines title 'insertSortaverage' smooth csplines, \
     'datos.txt' using 1:4 with lines title 'insertSortworst' smooth csplines

Cerrar terminal.

Solo Selección.
set title "Selection Sort"
set xlabel "Número de elementos"
set ylabel "Tiempo de ejecución"
plot 'datos.txt' using 1:5 with lines title 'selectionSortbest' smooth csplines, \
     'datos.txt' using 1:6 with lines title 'selectionSortaverage' smooth csplines, \
     'datos.txt' using 1:7 with lines title 'selectionSortworst' smooth csplines

Cerrar terminal.

Solo Merge.
set title "Merge Sort"
set xlabel "Número de elementos"
set ylabel "Tiempo de ejecución"
plot 'datos.txt' using 1:8 with lines title 'mergeSortbest' smooth csplines, \
     'datos.txt' using 1:9 with lines title 'mergeSortaverage' smooth csplines, \
     'datos.txt' using 1:10 with lines title 'mergeSortworst' smooth csplines

4. Para guardar nuestro grafico utilizaremos:

set term png
set output 'grafico.png'
replot


Graciasss por leerme. Atte Juan Faz.
