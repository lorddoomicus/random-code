#!env python
#
# This will calculate the dates of easter using Spencer Jones Method as 
# documented in "Astronomical Formulae for Calculators" 4th ed.
#
# (c) Derrik Walker v2.0
# This is licensed for use under the GNU General Pulbic License v2
#
# 2015-06-30	dwalker		Initial Python Version
#				Ported from a BASIC program written on an Atari ST many years ago
# 2015-08-06	dwalker		Fixed the range problem so that year2 is actually included in the output
# 2015-11-11	dwalker		Made it more "object orientated"
# 2016-03-27	dwalker		Added a "TODAY!" to the output if easter is today.
# 2020-11-14    dwalker		updated to work under python 3 under pyenv
# 2022-06-18	dwalker		Fixed a bug with the TODAY feature where it was ignoring the month
#

from datetime import date
import sys, argparse

parser = argparse.ArgumentParser( description='Calculates the days of easter', epilog='year2 > year1 > 1583' )
parser.add_argument( 'year1', type=int )
parser.add_argument( 'year2', type=int )
args = parser.parse_args()

today = date.today()

class easter:

	month = 0 
	day = 0	

	def __init__( self, year ):


		a = year % 19
		b = year // 100
		c = year % 100
	
		d = b // 4
		e = b % 4

		f = (b + 8) // 25

		g = ( b - f + 1) // 3

		h = (19 * a + b - d - g + 15) % 30

		i = c // 4
		k = c % 4

		l = ( 32 + 2 * e + 2 * i - h - k) % 7

		m = ( a + 11 * h + 22 * l ) // 451
	
		n = ( h + l - 7 * m + 114 ) // 31
		p = ( h + l - 7 * m + 114 ) % 31

		easter.day = p + 1 
		easter.month = n
		easter.year = year


	def display( self ):

		day = easter.day

		if easter.month == 3:
			month = "Mar"
		elif easter.month == 4:
			month = "Apr"
		else:
			print( "ERR" )
			sys.exit(3)

		year = easter.year
		
		if ( today.day == easter.day ) and ( today.month == easter.month ) and ( today.year == easter.year):
			print("{} {:2d}, {} TODAY!" .format( month, day, year) )

		else:
			print( "{} {:2d}, {}" .format( month, day, year ))

	### End display function ###

### End of easter class ###

# Check a the years

if args.year1 < 1583:
	print( "ERRR!!!:year1 must be > 1583" )
	parser.print_help()
	sys.exit(1)

if ( args.year2 < args.year1 ) or ( args.year1 < 1583 ):
	print( "ERR!!! {} > {}" .format( args.year1, args.year2 ))
	parser.print_help()
	sys.exit(1)

for year in range( args.year1, args.year2 + 1 ): # Need to include y2!
	easter( year ).display()
