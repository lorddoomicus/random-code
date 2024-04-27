#!/bin/bash
# 
# This is meant to be run via a Platypus created application
# Build a macOS droppable with: 
#
#       platypus -D -a "Sync Crap" -o 'Text Window' -u "Derrik Walker" -V 2.1 sync-crap.sh
#
# (c) 2021 Derrik Walker v2.0
# This is licensed for use under the GNU General Public License v2
#
#
# 2021-01-02	dwalker		Initial Version
# 2023-12-29	dwalker		New version 2 - a complete rewrite that gets input from config file
#				Instead of internal scripts
# 2024-04-27	dwalker		Added to always exclude .Trash and .DS_Store on all copies
#

# Conf file
#
# A csv file with these Fields:
# Source,Dest,exclude,keep
#
#	Source: The source as would be written for rsync
#	Dest: The destination under /Volumes/Backups/\ {1,2}/ as written for rsync
#	excluse: Anything other than tmp and Downloads that needs to be excluded
#	keep: Make a bzip'd tar file of the downloaded data and keep it in source/backup
#

#
# Set this to where ever you aws command is installed if you need to sync S3 content
aws=$HOME/.pyenv/shims/aws

if [ -e "sync-crap.conf" ]
then
	conf="sync-crap.conf"

elif [ -e "$HOME/lib/sync-crap.conf" ]
then
	conf="$HOME/lib/sync-crap.conf"
else
	echo "No conf file found - nothing to do"
	exit 1
fi

grep -v ^# $conf | sed '/^$/d' | while read line
do

	# echo $line

	src=$( echo $line  | cut -d, -f1 )
	dst=$( echo $line  | cut -d, -f2 )
	excl=$( echo $line | cut -d, -f3 )
	keep=$( echo $line | cut -d, -f4 )

	echo "source: $src"
	echo "dest: /Volume/Backups/ {1,2}/$dst"  
	echo "exclude: $excl .Trash .DS_Store tmp and Downloads"
	echo "keep: $keep" 

	for backup in /Volumes/Backups\ *
	do

		work="${backup}/${dst}"
		back="${work}/backup"
		keepf="$back/$( date +%Y%m%d ).tar.bz"

		if [ ! -d "$work" ]
		then
			mkdir -p "$work"
		fi

		cd "$work"

		echo "-----------------------------------------------------"
		echo backing up $src to $work
		echo "-----------------------------------------------------"

		if echo $src | grep '^/Volumes' > /dev/null
		then
			if [ ! -d $src ]
			then
				echo $src is not mounted, skipping
				continue
			fi
		fi

		if echo $src | grep ^s3 > /dev/null 
		then
			$aws s3 sync "$src" . 
		else
			if [ "$excl" ]
			then
		 		rsync -av "${src}"/ --timeout=60 --exclude .Trash --exclude .DS_Store --exclude tmp --exclude Downloads --exclude "$excl" .
			else
		 		rsync -av "${src}"/ --timeout=60 --exclude .Trash --exclude .DS_Store --exclude tmp --exclude Downloads .
			fi
		fi
		echo "-----------------------------------------------------"
		echo

		if [ "$keep" == "yes" ]
		then
			if [ ! -d "$back" ]
			then
				mkdir -p "$back"
			fi	
			
		 	if [ -e "$keepf" ]
			then
				echo "$keep already exists, skipping"
			else
				echo "taring $work to $keepf"
				tar -cvjf "$keepf" --exclude backup . 
			fi
		fi	

		echo "-----------------------------------------------------"
	done

	echo
done
