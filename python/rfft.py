#!env python
#
# (c) Derrik Walker v2.0
# This is licensed for use under the GNU General Pulbic License v2
#
# 2016-06-12	dwalker		Initial Release
# 2022-06-18	dwalker		Updated to run under Python3 and pyenv

import argparse
import matplotlib.pyplot as plt
import numpy as np
from numpy.fft import rfft, rfftfreq

parser = argparse.ArgumentParser( description='Plots the real fft of a list of real numbers' )
parser.add_argument( '--rate', type=int, help="The sample rate, default is 1", default=1 )
parser.add_argument( 'file', help="A text file of numbers, one per line" )
args = parser.parse_args()

file = args.file

rate = args.rate

with open( file ) as f:
    data = f.readlines()

signal = np.array( data )

fft = abs( rfft( signal ) ) / ( signal.size/2 )
freq = abs( rfftfreq( signal.size, d=1/rate ) )

plt.title( "FFT of Signal" )
plt.xlabel( "Frequency (Hz) " )
plt.ylabel( "Magnitude" )
plt.plot( freq, fft ) 
plt.show()
