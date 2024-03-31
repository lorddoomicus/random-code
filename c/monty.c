/*
 * This will demonstrate the solution to the Monte Hall paradox
 *
 * During the game, a player is offered to pick one of three doors for a prize.
 * They are then shown what was behind one door, and then given the option
 * to switch doors.
 *
 * More can be read at:
 *	https://en.wikipedia.org/wiki/Monty_Hall_problem
 *
 * Basically, here, for each game, a winning door is randomly selected,
 * then the player randomly selects a door.  If the player's door matched the
 * winning door, then player would have won by not switching, if not, then
 * the player would have won by switching.  These are counted for each game and
 * printed at the end.
 *
 * This is ported from a BASIC program written many eons ago for the C=64 Computer.
 * 
 * Compile with:
 *	Mac/Linux:
 *		gcc -o monty monty.c
 *	Amiga:
 *		vc -c99 +aos68k -o monty monty.c  -lamiga -lauto 
 *
 * (c) 2014 Derrik Walker v2.0
 * This is licensed for use under the GNU General Public License v2
 * 
 * 2014-04-24 	dwalker		Initial version
 * 2024-03-31	dwalker		Updated to run on an Amiga
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main( int argc, char **argv ) {

	int i, p, w, sw=0, nsw=0;

	int max = 1000000;

	srand( time( 0 ));

	for( i=0; i< max ; i++ ) {
	
		w = rand() % 3 + 1;
		p = rand() % 3 + 1;

		if( w == p )  nsw++;  else  sw++; 
	}

	printf( "After playing %d games ... \n", max );	
	printf( "\tWinning with Switching:    %d times\n", sw );
	printf( "\tWinning without Switching: %d times\n", nsw );
}
