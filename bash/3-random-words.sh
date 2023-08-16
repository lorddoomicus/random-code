#!/bin/bash
#
# Build a macOS clickable with: 
#
#	platypus -a "3 Random Words" -o 'Text Window' -u "Derrik Walker" -V 1.0 3-random-words.sh
#
# (c) 2022 Derrik Walker v2.0
# This is licensed for use under the GNU General Public License v2
#
# 2022-10-23	dwalker		Initial Version

dict=/usr/share/dict/web2
n_words=$( wc -l $dict | awk '{print $1}' )
count=3

dev=/dev/urandom

for i in $( seq 1 $count )
do
	rnd_no=$( od -vAn -N4 -t u4 < $dev )
	no=$(( rnd_no % n_words ))
	word=$( sed -n $no\p $dict )
	echo $word
done
