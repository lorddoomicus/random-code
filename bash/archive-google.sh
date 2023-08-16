#!/bin/bash
#
# copies google takeouts to s3 archive bucket
#
# Make macOS droppable with:
#
#	platypus -D -a "Archive Google" -o 'Text Window' -u "Derrik Walker" -V 1.0 archive-google.sh
#
# (c) 2016 Derrik Walker v2.0
# This is licensed for use under the GNU General Public License v2
#
# 2023-07-01	dwalker		Initial Version
# 2023-07-21	dwalker		Yeah ... ERRR

. /Users/dwalker/lib/s3_buckets.sh

s3_dir=$google_archive

if [ -e "$1" ] 
then
	takeout=$1
	echo processing $takeout
else
	echo file $1 not found - maybe you forgot to drop the takeout on me
	exit 1
fi

check=$( file $takeout | grep -o "POSIX tar archive" )
# echo takeout file $takeout is $check

if [ "$check" == "POSIX tar archive" ]
then
	echo it appears that $tackout needs to be compressed
	bzip2 --best $takeout
	$takeout=${takeout}.bz2
fi

/Users/dwalker/.pyenv/shims/aws s3 cp $takeout $s3_dir

