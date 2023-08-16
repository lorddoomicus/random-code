#!/bin/bash
#
# A wrapper to call cam_to_mp4 on specific directories as used by ssvf.sh and sdvf.sh
#
# (c) 2016 Derrik Walker v2.0
# This is licensed for use under the GNU General Public License v2
#
# 2016-07-06	dwalker		Initial Version
# 2017-01-11	dwalker		Updated for supporting no specific car
# 2023-07-15	dwalker		Added copyright and cleaned up code
#

#
# the dirs we MUST be cd'd into one of these, or else this script may cause more problems than it will solve ...
#
list="dashcam frntprch kitchen"

lfile=/tmp/l.txt
echo $list | tr  " " "\n" > $lfile

if ( ! basename $(pwd) | grep -f $lfile > /dev/null  )
then
	echo errr
	exit 1
fi

for d in * 
do 
	if [ -d $d ]
	then
		cd $d 
		pwd 
		cam_to_mp4.sh
		cd .. 
	fi
done

