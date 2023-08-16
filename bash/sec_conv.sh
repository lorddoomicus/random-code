#!/bin/bash
#
# Script to use the ssvf command to bulk convert the security camera footage
# 
# If the media card is formatted on the Uniden, it's called "disk" ... 
# 
# (c) 2017 Derrik Walker v2.0
# This is licensed for use under the GNU General Public License v2
#
#
# 2016-01-17	dwalker		Initial version
# 2016-01-30	dwalker		Added support for sec_to_mp4
# 2023-07-15	dwalker		Cleaned up code and added copyright
#

cd /run/media/$(whoami)/disk/MFG

for d in * 
do
	cd $d 
	ssvf.sh
	cd .. 
done
