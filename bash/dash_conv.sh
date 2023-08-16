#!/bin/bash
#
# Script to use the sdvf.sh command to bulk convert the dashcam footage
# 
# If the media card is formatted on the dashcam, it's called "VOLUME1" ... 
# And that may be different on platforms other than Fedora XFCE spin!
#
# (c) 2016 Derrik Walker v2.0
# This is licensed for use under the GNU General Public License v2
#
# 2016-06-05	dwalker		Initial version
# 2023-07-15	dwalker		Cleaned up code and added copyright
#

cd /run/media/$(whoami)/VOLUME1/DCIM/

for d in * 
do
	cd $d 
	sdvf.sh
	cd .. 
done
