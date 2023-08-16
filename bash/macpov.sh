#!/bin/bash
#
# Build a macOS droppable with: 
#
#	platypus -D -a "macpov" -o 'Text Window' -u "Derrik Walker" -V 1.0 macpov.sh
#
# (c) 2023 Derrik Walker v2.0
# This is licensed for use under the GNU General Public License v2
#
# 2023-08-12	dwalker		Initial Version
#

# Optional config file

POVRAY=/opt/homebrew/bin/povray

# if [ ! "$width" ] ; then width=2048 ; fi
# if [ ! "$height" ] ; then hight=1536 ; fi

if [ ! "$1" ]
then
	echo "Looks like you forgot to drop a file on me"
	exit 1
fi

path=$( dirname "$1" )
infile=$( basename "$1" )
inifile=$( basename -s .pov "$1" ).ini

cd "$path"

if [ -e $inifile ]
then
	echo inifile $inifile found
	# $POVRAY +I${infile} +V +W${width} +H${hight} $inifile
	$POVRAY +I${infile} +V $inifile
else
	# $POVRAY +I${infile} +V +W${width} +H${hight}
	$POVRAY +I${infile} +V
fi

