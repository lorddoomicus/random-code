#!env python
#
# Simple Monte-Carlo pi simulation using numpy array's in vectory kind of way
# in this case pi = 4* ( random_points_in_circle / random_points_in_square )
#
# The number of loops is averated over the number of runs
#
# This requires to have numpy installed
#
# (c) Derrik Walker v2.0
# This is licensed for use under the GNU General Pulbic License v2
#
# 2016-01-20	dwalker	Initial Version
# 2020-11-14    dwalker Updated to run under Python 3 under Pyenv
#

import numpy as np

loops = 1000000
number = 1000
 
p = 0

for i in range( number ):
	o = np.random.rand(loops)**2 + np.random.rand(loops)**2
	p += 4 * ( np.sum( o < 1 ) /  loops ) 

print ( "Avg of", number, "runs of a", loops, "loop pi simulation is", p / number )
