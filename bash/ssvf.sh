#!/bin/bash
#	ssvf.sh - sort through security video footage from a Uniden UDR744 
#	
#	Sorts through files in the local directory with an asf extension
# 	and a given file name:
#
#		HHMMSS[A|P]#
#
#		Where:
#			HH = hour
#			MM = minute
#			SS = Second
#			A|P = AM or PM
#			# = camera number
#
#		and it represents the time and camera number of the video
#		footage.  The date of the file is used for the date to
#		go with the time as above.
#
#		This script will make directories as camera/date under basedir
#		put the files in those directories as they are decoded. Then
#		the files will be time stamped ( or touched in the UNIX sense )
#		with the correct Date and time stamp. 
#
# (c) 2015 Derrik Walker v2.0
# This is licensed for use under the GNU General Public License v2
#
# 2015-11-05	dwalker		Initial Version
# 2023-07-15	dwalker		Cleaned up code and added copyright

#
# some stuff we need to get started
#
basedir=$HOME/Videos/security

camera1="frntprch"
camera2="kitchen"
camera3="notyet3"
camera4="notyet4"

for file in *.ASF
do
	#
	# set up some varibles we need ...
	#
	date=$(ls -l $file | awk '{print $6 " " $7}')
	
	time=$(basename -s .ASF $(ls -l $file | awk '{print $9}') )

	hour=$(echo $time | cut -b1,2)	
	min=$(echo $time | cut -b3,4)	
	sec=$(echo $time | cut -b5,6)	
	ampm=$(echo $time | cut -b7)	
	camera=$(echo $time | cut -b8)	


	#
	# convert PM to 24 hour time
	#
	if [[ $ampm == "P" ]]
	then
		# echo 24 hour = $hour
		if [[ $((10#$hour)) -ne 12 ]]
		then
			# (( hour += 12 ))
			hour=$(expr $hour + 12 )
		fi
	fi
	
	if [ $ampm == "A" ]
	then
		if [[ $((10#$hour)) -eq 12 ]]
		then
			hour=0
		fi
	fi

	#
	# get the location of each camera
	# the UDR744 supports up to 4 cameras
	#

	case $camera in
	1)
		loc=$camera1
		;;
	2)
		loc=$camera2
		;;
	3)
		loc=$camera3
		;;
	4)
		loc=$camera4
		;;
	*)
		loc="ERRR"
		;;

	esac

	echo processing $file ... $date $hour:$min:$sec from $loc

	dir=$basedir/$loc/$(date -d "$date" +%Y-%m-%d)	
	# echo $dir

	# 
	# create a directory for the date, if needed
	#

	if [[ ! -e $dir ]]
	then
		mkdir -p $dir
	fi

	#
	# copy the file, and touch it with the correct timestamp
	#

	cp $file $dir
	touch -d "$date $hour:$min:$sec" $dir/$file

done
