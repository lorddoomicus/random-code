#!env python
#
# (c) Derrik Walker v2.0
# This is licensed for use under the GNU General Pulbic License v2
#
# 2015-11-10	dwalker		initial python version
#				Ported from a C program written about a year ago
# 2022-06-18	dwalker		Updated to use python 3 under pyenv.
#

import math, argparse, sys

parser = argparse.ArgumentParser( description="Calculates 'n choose k' or 'n permutations of k'", epilog='NOTE: 0 < k < n'  )
parser.add_argument( 'n', type=int )
parser.add_argument( 'k', type=int )
group = parser.add_mutually_exclusive_group()
group.add_argument( '-c', help="caclulate n choose k", action='store_true' )
group.add_argument( '-p', help="caclulate n permutations of k", action='store_true' )
args = parser.parse_args()

n = args.n
k = args.k

if ( n < 0 ) or  ( k < 0 ) or ( n < k ):
	print ( "ERRR!!!" )
	parser.print_help()
	sys.exit(1)

if args.c:
	print ( math.factorial( n ) / ( math.factorial( k ) * math.factorial( n - k )) )

elif args.p:
	print ( math.factorial( n ) /  math.factorial( n - k ))

