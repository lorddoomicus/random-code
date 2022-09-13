#!env python
#
# Add the digits of a number together
#
# (c) Derrik Walker v2.0
# This is licensed for use under the GNU General Pulbic License v2
#
# 2015-11-02	dwalker		Initial Version
# 2020-11-14	dwalker		Updated to use python 3 under pyenv.
#

import argparse

parser = argparse.ArgumentParser( description='Add digits of a number together.' )
parser.add_argument( 'n', type=int, help="Number to add digits together" )
args = parser.parse_args()

#
# This takes in an int, and the add method then adds the digits of that int
# and returns it's value
#
class addem:

	ints = []

	def __init__( self, num ):

		addem.ints = list( map( int, str( num )) )


	def add( self ):

		sum = 0

		for i in range( 0, len( addem.ints )):
			sum += addem.ints[i]

		return sum

print( addem( args.n ).add() )
