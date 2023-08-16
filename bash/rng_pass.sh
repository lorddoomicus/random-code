#!/bin/bash 
#
# This simple script makes a random password using the Pi's random number generator.
#
# Usage: rng_pass.sh [-c[1,2,3,4,5]|-s|-n] [-L <length>] [-h]
#
#	Where:
#		-c 0 -n		Numbers Only
#		-c 1 		Just upper and lower case letters 
#		-c 2 		and  numbers
#		-c 3 -s		and . - _ $ * # @ ! +
#		-c 4		and % ^ & = ? , ~ [ ]  
#		-c 5, default	Just about any printable ASCII character ( not including space, tab, single quotes )
#
#		-L <lenght> - sets the length of the password, default is 16
#
#		-h prints the help message
#
# NOTE: If a hardware random number generator exists, such as on a Raspberry Pi, it will require root privileges.
#
# (c) 2017 Derrik Walker v2.0
# This is licensed for use under the GNU General Public License v2
#
# 2017-06-28	dwalker		Initial Version
# 2017-07-08	dwalker		Added options for length and simpler password
# 2017-08-07	dwalker		Added multiple levels of complexity
# 2017-09-14	dwalker		Cleaned up the cmd options so they made more sense.
# 2018-06-22	dwalker		Added option for only numbers
# 2020-04-04	dwalker		Added option to use /dev/urandom if /dev/hwrng is not available
# 2023-07-15	dwalker		Fixed issue with tr on macOS that would cause "illegal byte sequence"
#

export LC_CTYPE=C
export LANG=C

length=16	# password length - default is 16
complexity=5	# by default, make as complex as possible


if [ -c /dev/hwrng ]
then
	dev=/dev/hwrng	# Direct hardware random number generator 
else
	dev=/dev/urandom # Entropy driven random number generator
fi

while getopts ":hnsc:L:" opt; do
	case $opt in
	L)
		length=$OPTARG
	;;

	c)
		complexity=$OPTARG
	;;

	n)
		complexity=0
	;;

	s)
		complexity=3
	;;

	h)
		echo "Usage: $0 [-c[1,2,3,4,5]|-s] [-L <length>] [-h]"
		exit 0
	;;
	
	\?)
      		echo "Invalid option: -$OPTARG" >&2
		exit 1
	;;
	:)
		echo "Option -$OPTARG requires an argument." >&2
		exit 1
	;;
	esac
done

# echo "complexity = $complexity"

if ! [[ $complexity =~ ^[0-5]$ ]] 
then
	echo "Invalid complexity level!"
	exit 1
fi

if [ $complexity -eq 0 ]
then
	tr -dc '0-9' < $dev | dd bs=$length count=1 2>/dev/null

elif [ $complexity -eq 1 ]
then
	tr -dc 'A-Za-z' < $dev | dd bs=$length count=1 2>/dev/null

elif [ $complexity -eq 2 ]
then
	tr -dc 'A-Za-z0-9' < $dev | dd bs=$length count=1 2>/dev/null

elif [ $complexity -eq 3 ]
then
	tr -dc 'A-Za-z0-9.-_$*#@!+' < $dev | dd bs=$length count=1 2>/dev/null

elif [ $complexity -eq 4 ]
then
	tr -dc 'A-Za-z0-9.-_$*#@!+%^&=?,~[]' < $dev | dd bs=$length count=1 2>/dev/null
	
else
	tr -dc 'A-Za-z0-9.-_$*#@!+%^&=?,~[](){};:"`' < $dev | dd bs=$length count=1 2>/dev/null
fi

echo 
