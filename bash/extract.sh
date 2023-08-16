#!/bin/bash
#
# Script to use ffmpg to extract a given segment from a dascham or security video. 
#
# This script assumes that video files were made with by ssvf or sdvf, but it should
# work on any video file compatable with ffmpeg
#
# (c) 2016 Derrik Walker v2.0
# This is licensed for use under the GNU General Public License v2
#
# 2016-07-16	dwalker		Initial version
# 2016-08-05	dwalker		Fixed the same date problem that cam_to_mp4 had
# 2023-07-15	dwalker		Cleaned up code and added copyright
#

if [ "$#" -ne 3 ]
then
	echo "usage: $(basename $0) <video_file> <start_time> <how_long>"
	echo "where <start_time> is in the form hh:mm:ss.s and <how_long> is in seconds"
	exit 1
else
	file=$1
	start=$2
	time=$3
fi

type=${file#*.}

mp4=$( basename -s $type $file )_edited.mp4
echo -n extractig ${time}s starting at $start from and converting $file to $mp4 ...

ffmpeg -i $file -ss $start -t $time $mp4 

date=$( TZ=utc ls -l --time-style=+"%Y-%m-%d %H:%M:%S" $file | awk '{print $6 " " $7}' )
	
echo "setting date: $date"

exiftool -CreateDate="$date" $mp4	>> /tmp/$mp4.out 2>&1
exiftool -TrackCreateDate="$date" $mp4	>> /tmp/$mp4.out 2>&1
exiftool -MediaCreateDate="$date" $mp4	>> /tmp/$mp4.out 2>&1

touch -r $file $mp4	# preserve time and date of file

echo Cleaning up ...

rm *_original
