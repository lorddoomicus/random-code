/*
 * Simulates a dice roll, with arbitrary sides, number of dice, or rolls
 *
 * compile with:
 *	Mac/Linux:
 *		gcc -O3 -o dice dice.c
 *	Amiga:
 *		vc  +aos68k -o dice -I$HOME/Code/Amiga/amiga-cc/extra/include dice.c  -lamiga -lauto -L$HOME/Code/Amiga/amiga-cc/extra/ -lposix
 *
 * (c) 2012 Derrik Walker v2.0
 * This is licensed for use under the GNU General Public License v2
 *
 * 2012-12-11	dwalker		Initial Version
 * 2014-01-28	dwalker		Added proper support for cmd args
 * 2015-05-27	dwalker		Added error checking and fixed help
 * 2024-03-31	dwalker		Updated to run on an Amiga
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define NAME "dice"
#define NRML	0
#define SPR	1

void usage( int type ); 

int main ( int argc, char *argv[] ) {

	int number = 2, sides = 6, rolls = 1, total;

	int i, j, opts;

	char *ender;

/*  	Processes cmd args 	*/

	while (( opts = getopt( argc, argv, "hHs:n:r:" )) != -1 )
	
		switch( opts ) {

			case 's':
				sides = strtol( optarg, &ender, 10 );

				if ( ( sides  < 1 ) || strcmp( ender, "\0" ) )
					usage( NRML );

				break;

			case 'r':
				rolls = strtol( optarg, &ender, 10 );

				if ( ( rolls < 1 ) || strcmp( ender, "\0" ) )
					usage( NRML );

				break;

			case 'n':
				number = strtol( optarg, &ender, 10 );

				if ( ( number  < 1 ) || strcmp( ender, "\0" ) )
					usage( NRML );

				break;

			case 'h':
				usage( NRML );
				return 0;

			case 'H':
				usage( SPR );
				return 0;

			case '?':
				usage( NRML );
				return 1;

			default:
				return 0;
		}


/*  	actual program work done here 	*/

	srand( time(0) );

	for( i = 0; i < rolls; i++ ){ 

		total = 0;

  		for( j = 0; j < number; j++ ){
			total += ( rand() % sides + 1 ); 
		}

		printf( "%i\n", total ); 
	}

	return 0;
} 

void usage( int type ) {

	printf ( "usage: %s", NAME ); 
	printf ( " [-h|H] [-s <sides>] [-n <number>] [-r <rolls>] \n" );  

	if( type == SPR ) {	/* super help */
		printf ( "\nWhere:\n" );
		printf ( "\t-h: simple help\n" );
		printf ( "\t-H: super help\n" );
		printf ( "\t-s: specify the number of sides, default is 6\n" );
		printf ( "\t-n: specify the number of dice, default is 2\n" );
		printf ( "\t-r: specify the number of rolls, default is 1\n" );

		printf ( "\nNotes:\n" ); 
		printf ( "\t- simulates a dice roll\n" );
		printf ( "\t- arbitrary sides, number of dice or rolls\n" );
		printf ( "\t- all the input values must be >0\n" );
		printf ( "\t- default simulates 2 6-sided dice rolled once\n" );
	}

	exit( 1 );
}
