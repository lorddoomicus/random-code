#!/bin/bash
#
# Script to use ffmpg to convert the secuity camera  and dashcam vidoes to mp4's that can be imported into shotwell or other similar program.  
#
# This scrip assumes you are in the directory with the ASF files as created by ssvf or sdvf
#
# (c) 2016 Derrik Walker v2.0
# This is licensed for use under the GNU General Public License v2
#
# 2016-01-30	dwalker		Initial version
# 2016-02-20	dwalker		Fixed time to be utc as needed for mp4 files
# 2016-07-05	dwalker		Added support for MOV files as well
# 2016-08-05	dwalker		Fixed a bug that was causing the time on the file to be wrong
# 2023-07-15	dwalker		Cleaned up the code and added the copyright
#

for file in * 
do
	type=${file#*.}

	if [[ $type = "MOV" || $type = "ASF" ]]
	then
		ext=".$type"
	else
		echo not processing $file ... NOT AN ASF OR MOV!!
		continue
	fi

	mp4=$( basename -s $ext $file ).mp4
	echo -n converting $file to $mp4 ...

	ffmpeg  -i $file -strict -2 $mp4 > /tmp/cam_$mp4.out 2>&1

	date=$( TZ=utc ls -l --time-style=+"%Y-%m-%d %H:%M:%S" $file | awk '{print $6 " " $7}' )
	
	echo "setting date: $date"

	exiftool -CreateDate="$date" $mp4	>> /tmp/$mp4.out 2>&1
	exiftool -TrackCreateDate="$date" $mp4	>> /tmp/$mp4.out 2>&1
	exiftool -MediaCreateDate="$date" $mp4	>> /tmp/$mp4.out 2>&1
	
	touch -r $file $mp4	# preserve time and date of file
done

echo Cleaning up ...

rm *_original
