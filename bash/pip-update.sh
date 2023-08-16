#!/bin/bash
#
# (c) 2020 Derrik Walker v2.0
# This is licensed for use under the GNU General Public License v2
#
# 2020-11-28	dwalker		Initial verison
# 2020-12-05	dwalker		Added pip upgrade
# 2021-01-02	dwalker		Fixed a Typo

echo checking for latest pip verison

python -m pip install --upgrade pip 

echo checking for python updates with pip ...

if [ "$( pip list --outdated )" == "" ] 
then
	echo nothing to update
        exit 0	
fi

echo "updatting: "
pip list --outdated

sleep 3
pip list -o | cut -f1 -d' ' |  tr " " "\n" | awk '{if(NR>=3)print}' | xargs -n1 pip install -U
