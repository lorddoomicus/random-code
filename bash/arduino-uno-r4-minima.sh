#!/bin/bash
#
# # Make macOS droppable with:
#
#	platypus -D -a "Arduino R4 minima" -o 'Text Window' -u "Derrik Walker" -V 1.0 arduino-uno-r4-minima.sh 
#
# (c) 2023 Derrik Walker v2.0
# This is licensed for use under the GNU General Public License v2
#
# 2023-07-08	dwalker		Initial Version	

#
# fbqn for a board can be obtained with arduino-cli board list while the board is plugged in
#
fqbn="arduino:renesas_uno:minima" 
port=$( /opt/homebrew/bin/arduino-cli board list | grep $fqbn | awk '{print $1}' )

usage="Usage: $0 sketch"

if [ $# -ne 1 ]
then
 	# echo $usage
	echo "Maybe you forgot to drop the sketch on me?"
 	exit 1
fi

sketch=$1

echo compiling and uploading $sketch to port $port on $fqbn

/opt/homebrew/bin/arduino-cli compile --fqbn $fqbn $sketch 
/opt/homebrew/bin/arduino-cli upload -p $port --fqbn $fqbn $sketch 
