#!env python
#
# Findes Primes using the Sieve of Eratosthenes 
#
# (c) Derrik Walker v2.0
# This is licensed for use under the GNU General Pulbic License v2
#
# 2016-06-07	dwalker		Initial Version
# 2020-11-14	dwalker		Updated to use python 3 under pyenv.
#

import argparse

parser = argparse.ArgumentParser( description='Calculates primes to a given number.' )
parser.add_argument( 'n', type=int, help="Number to get primes too" )
args = parser.parse_args()

number = args.n
primes = [True for i in range( number + 1 )]

for i in range( 2, number + 1 ):
	if( primes[i] == True ):
		for j in range( i * i, number + 1, i ):
			primes[j] = False
 
for i in range( 2, number + 1 ):
	if primes[i]:
		print( i )
