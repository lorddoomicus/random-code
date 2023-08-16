#!/bin/bash
#
# copies facebook backups to s3 archive bucket
#
# Make macOS droppable with:
#
#	platypus -D -a "Archive Facebook" -o 'Text Window' -u "Derrik Walker" -V 1.0 archive-facebook.sh
#
# (c) 2016 Derrik Walker v2.0
# This is licensed for use under the GNU General Public License v2
#
# 2023-07-01	dwalker		Initial Version
# 2023-07-21	dwalker		Yeah ... ERRR

. /Users/dwalker/lib/s3_buckets.sh

s3_dir=$facebook_archive

if [ -e "$1" ] 
then
	backup=$1
else
	echo file $1 not found - maybe you forgot to drop the backup on me
	exit 1
fi

/Users/dwalker/.pyenv/shims/aws s3 cp $backup $s3_dir

