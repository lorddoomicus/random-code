#! /bin/bash
#
# sort through dashcam video footage
# 
# assumes you are in the dir containing the videos on the memory card.
#
# for the dirs with the files, there is one per day, and the format is: XXXXMMDD  
#	not sure what the XXXX is about, but we only need the month and day
#
# file format is HHMMXXXX.MOV - Again, we only need the hour and minute
#
# (c) 2016 Derrik Walker v2.0
# This is licensed for use under the GNU General Public License v2
#
# 2016-07-05	dwalker		Initial Version
# 2017-01-04	dwalker		Removed car spacific bits to support the CX-5 as well
# 2017-01-11	dwalker		Fixed a little bug
#

basedir=$HOME/Videos/dashcam
# car="mazda3"

sos=$basedir/SOS				# no clue what this is about, but its for holding SOS files

year=$(date +%Y)				# will break if files cross year boundries
month=$( basename `pwd` | cut -c 5-6 )
day=$( basename `pwd` | cut -c 7-8 )

date="$year-$month-$day"

# dir=$basedir/$car/$date
dir=$basedir/$date

if [[ ! -e $dir ]]
then
	mkdir -p $dir
fi

for file in *
do
	hour=$( echo $file | cut -c 1-2 )
	min=$( echo $file | cut -c 3-4 )
	sec="00"
	
	echo processing $file ... $date $hour:$min:$sec for dashcam 

	#
	# special handle SOS files for now, at least until I get a grasp on what the heck they are
	#
	if [[ $(echo $file | cut -c 1-3) == "SOS" ]] 
	then 
		echo '	!!!!! SOS FILE !!!!! '
		cp $file $sos
		echo

	else 
		cp $file $dir
		touch -d "$date $hour:$min:$sec" $dir/$file
	fi
done

