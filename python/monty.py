#!env python
#
# This will demenstrate the solution to the Monte Hall paradox
#
# During the game, a player is offered to pick one of three doors for a prize.
# They are then shown what was behind one door, and then given the option
# to switch doors.
#
# More can be read at:
#	https://en.wikipedia.org/wiki/Monty_Hall_problem
#
# Basically, here, for each game, a winning door is randomly selected,
# then the player randomly selects a door.  If the player's door matched the
# winning door, then player would have won by not switching, if not, then
# the player would have won by switching.  These are counted for each game and
# printed at the end.
#
# This is ported from a BASIC program written many eons ago for the C=64 Computer.
#
# (c) Derrik Walker v2.0
# This is licensed for use under the GNU General Pulbic License v2
#
# 2015-07-21	dwalker	Initial Version in Python
# 2020-11-14    dwalker Updated to work under Python3 under Pyenv
#

import random

games = 1000000 	# number of games

switch = 0
stayed = 0

for game in range( games ):
	winner = random.randrange( 0, 3 )	# winning door
	player = random.randrange( 0, 3 )	# players initial door

	if player == winner:
		stayed += 1
	else:
		switch += 1

print( "After {} games of Lets Make a Deal ... " .format( games ) )
print( "\t{} won by switching doors" .format( switch ) )
print( "\t{} won by staying with the originally chosen door" .format( stayed ) )
