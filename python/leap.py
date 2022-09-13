#!env python
#
# This will calculate the leap years 
#
# (c) Derrik Walker v2.0
# This is licensed for use under the GNU General Pulbic License v2
#
# 2016-02-27	dwalker	Initial Python Version
#		Ported from a PERL program written many years ago
# 2020-11-14    dwalker updated to use python 3 under pyenv

import sys, argparse

parser = argparse.ArgumentParser( description='Calculates leap years.', epilog='year2 > year1 > 1583' )
parser.add_argument( 'year1', type=int )
parser.add_argument( 'year2', type=int )
args = parser.parse_args()

class leap:

	def __init__( self, year ):
	
		if year % 4 == 0:
			if ( year % 100 == 0 )  and ( year %400 != 0 ):
				leap.year = 0
			else: 
				leap.year = year

		else:
			leap.year = 0 


	def display( self ):
		
		if leap.year != 0: 
		 	print( leap.year )

	### End display function ###

### End of leap class ###

# Check a the years

if args.year1 < 1583:
	print( "ERRR!!! year1 must be > 1583" )
	parser.print_help()
	sys.exit(1)

if ( args.year2 < args.year1 ) or ( args.year1 < 1583 ):
	print( "ERRR!!! {} > {}" .format( args.year1, args.year2 ))
	parser.print_help()
	sys.exit(1)

for year in range( args.year1, args.year2 + 1 ): # Need to include y2!
	leap( year ).display()
