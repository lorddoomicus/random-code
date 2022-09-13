#
#
# This is the gnuplot file that can be used for rfft 
# usage:
#	rfft < test.dat > test.fft
#	gnuplot rfft.plt
#
# This will leave test.jpg in the working directory
#
# (c) 2016 Derrik Walker v2.0
# This is licensed for use under the GNU General Pulbic License v2
#
# 2016-09-19	dwalker		Initial version                                       *
#

set autoscale
set terminal jpeg
set output "test.jpg"

set title "Real FFT of a Signal"
set xlabel "Frequency"
set ylabel "Magnitude"

set grid xtics ytics

plot "test.fft" using 1:2 with lines title "Real FFT"
