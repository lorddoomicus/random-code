#!/bin/bash
#
# usage:
# 	tivo2mp4.sh {TiVo_file} {mp4_file}
#
# (c) 2018 Derrik Walker v2.0
# This is licensed for use under the GNU General Public License v2
#
# 2018-08-12	dwalker		Initial Version
#

mak=2499016703	# Set this to your TiVo Media Access Key ... this one is old and no longer valid.
TDjar=$HOME/lib/TivoDecoder.jar

usage="tivo2mp4.sh {TiVo_file} {mp4_file}"

if [ $? -nq 2 ]
then
	echo usage: $usage
	exit 1
else
	tivo="$1"
	mp4="$2"
fi

java -jar $TDjar -i $tivo -o $mp4 -m $mak
