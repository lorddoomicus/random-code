#!/bin/bash
#
# Converts classic Mac text files with CR line enders to UNIX style with NL
# And makes the filename all lowercase. 
#
# Build a macOS droppable with: 
#
#	platypus -D -a "mac2unix" -o 'Text Window' -u "Derrik Walker" -V 1.0 mac2unix.sh
#
# (c) 2023 Derrik Walker v2.0
# This is licensed for use under the GNU General Public License v2
#
# 2023-08-12	dwalker		Initial Version
# 2023-08-14	dwalker		Updated to allow dropping multiple files
#

if [ ! $1 ]
then
	echo "Looks like you forgot to drop a file on me"
	exit 1
fi

for file in "$@"
do
	holdfile=$( mktemp )

	path=$( dirname "$file" )
	oldfile=$( basename "$file" )

	newfile=$( echo $oldfile | tr '[:upper:]' '[:lower:]' )

	cd "$path"

	echo path: $path
	echo oldfile: $oldfile
	echo newfile: $newfile

	echo processing ...

	tr '\r' '\n' < "$oldfile" > $holdfile
	mv $holdfile "$oldfile"

	mv "$oldfile" "$newfile"	# make it lowercase

	echo done
done
