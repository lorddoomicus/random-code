#!env python
#
# Shows the relationship between the sum of digits of an arbritrary number and '9'
#
# (c) Derrik Walker v2.0
# This is licensed for use under the GNU General Pulbic License v2
#
# 2015-10-27	dwalker	Initial Version
# 2020-11-14    dwalker Updated to run under Python3 under Pyenv
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

		addem.ints = list ( map( int, str( num )) )


	def add( self ):

		sum = 0

		for i in range( 0, len( addem.ints )):
			sum += addem.ints[i]

		return sum

### End of class addem
	
n = args.n

sum = addem( n ).add()		# add digits
diff = n - sum			# subtract from original number
nine = addem( diff ).add() 	# add the resulting digits

print( "num = ", n, ", sum = ", sum, ", diff = ", diff,  ", nine = ", nine )
