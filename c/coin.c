/*
 * Simulates a coin toss, with arbitrary flips, or number of coins
 * 
 * compile with:
 *	Mac/Linux:
 *		gcc -O3 -o coin coin.c
 *
 *	Amiga:
 *		vc  +aos68k -o coin -I$HOME/Code/Amiga/amiga-cc/extra/include coin.c  -lamiga -lauto -L$HOME/Code/Amiga/amiga-cc/extra/ -lposix
 *
 * (c) 2015 Derrik Walker v2.0
 * This is licensed for use under the GNU General Public License v2
 *
 * 2015-01-22	dwalker		Initial Version
 * 2015-05-28	dwalker		Added error checking and super help
 * 2022-04-09	dwalker		Added include for string.h and c99 compliance
 # 2024-03-31	dwalker		Updated to run on an Amiga
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#define NAME "coin"
#define NRML	0
#define SPR	1


#define HEADS 0
#define TAILS 1

#define SIDES 2

void usage( int type ); 

int main ( int argc, char *argv[] ) {

	int coin, number = 1, flips = 1, r = 0;
	int i, j, opts;
	char *ender;
	opterr = 0;

/* 	Processes cmd args 	*/

	while (( opts = getopt( argc, argv, "hHrn:f:" )) != -1 )
	
		switch( opts ) {

			case 'n':
				number = strtol( optarg, &ender, 10 );

				if ( ( number < 1 ) || strcmp( ender, "\0" ) )
					usage( NRML );

				break;

			case 'f':
				flips = strtol( optarg, &ender, 10 );

				if ( ( flips < 1 ) || strcmp( ender, "\0" ) )
					usage( NRML );
				break;

			case 'r':
				r = 1;
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
				number = 1;
				flips = 1;
		}

/*  	actual program work done here 	*/

	srand( time(0) );

	for( i = 0; i<number; i++ ) 

  		for( j = 0; j<flips; j++ ){

			coin = ( rand() % SIDES ); 
			
			if( r != 0 )	/* print raw number output */
				printf( "%i\n", coin );

			else 		/* print t or h output - default */
				if( coin == HEADS )
					printf( "h\n" );

				else if ( coin == TAILS )
					printf( "t\n" );

				else	/* should NEVER happen!! */
					printf( "ERR\n" ); 

		}

	return 0;
} 

void usage( int type ) {

	printf ( "usage: %s", NAME ); 
	printf ( " [-h] [-r] [-n number] [-f flips] \n" );

	if( type == SPR ) {     /* super help */
		printf ( "\nWhere:\n" );
		printf ( "\t-h: simple help\n" );
		printf ( "\t-H: super help\n" );
                printf ( "\t-r: specifies to use 0 for tails, 1 for heads\n" );
                printf ( "\t-n: specify the number of coins, default is 1\n" );
                printf ( "\t-f: specify the number of flips, default is 1\n" );

                printf ( "\nNotes:\n" );
                printf ( "\t- simulates a coin toss\n" );
		printf ( "\t- with arbitrary flips or number of coins\n" );
		printf ( "\t- all the input values must be >0\n" );
		printf ( "\t- default simulates a single coin toss\n" );
	}

	exit( 1 );
}
