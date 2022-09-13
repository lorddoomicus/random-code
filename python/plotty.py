#!env python
#
# plotty: 
#
# Generate a plot from arbritrary 1 or 2 column numerical data from standard input 
#
# usage:
#
#	./plotty --title "some data" --x "X-axis" --y "Y-axis" < infile
#	rfft < infile | plotty --title "fft"
#	
# The input is simply a line of ascii numbers, one or two per line seperated by a space
#
# This requires to have matplotlib installed
#
# (c) Derrik Walker v2.0
# This is licensed for use under the GNU General Pulbic License v2
#
# 2016-09-27	dwalker	Initial Version
# 2020-10-17    dwalker Updated to use Python 3 under pyenv
#

import argparse, sys
import matplotlib.pyplot as plt

parser = argparse.ArgumentParser( description='Plots one or two column numbers on STDIN.' )
parser.add_argument( '--title', help="The title" )
parser.add_argument( '--x', help="X-axis label" )
parser.add_argument( '--y', help="Y-axis label" )
args = parser.parse_args()

col1 = []
col2 = []

if not args.title:
	title = "Data"
else:
	title = args.title

if not args.x:
	x = "X"
else:
	x = args.x

if not args.y:
	y = "Y"
else:
	y = args.y

for line in sys.stdin:

	numbers = line.split()

	if len( numbers ) == 2:
		col1.append ( float ( numbers[0] ))
		col2.append ( float ( numbers[1] ))
	else:
		col1.append( float ( numbers[0] ))

if not col2:
	plt.plot( col1 )
else:
	plt.plot( col1, col2 )

plt.title( title )
plt.xlabel( x )
plt.ylabel( y )
plt.show()
