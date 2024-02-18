/*
 * A Russian Roulette game for two players
 *
 * Compile with:
 * 	clang russian.c -o russian
 * 
 * To compile for Amiga:
 * 	vc +aos68k -o russian  -I$HOME/Code/Amiga/amiga-cc/extra/include  russian.c -lamiga -lauto -L$HOME/Code/Amiga/amiga-cc/extra/ -lposix
 * 
 * (c) 2024 Derrik Walker v2.0
 * This is licensed for use under the GNU General Public License v2
 *
 * 2024-02-15	dwalker		Initial Version
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define CHAMBERS 6
#define TURNS 10
#define SPIN_TIME 1	/* Number of seconds it takes for the cylinder to spin */

int spinPull( char *player ) {


	/* Spin the cylinder and pull the trigger at a random chamber */
	printf( "Spinning chamber ... " );
	fflush( stdout );
	sleep( SPIN_TIME );

	printf( "%s, press enter to fire. ", player );
	fflush( stdin );
	while( getchar() != '\n' );

	return rand() % CHAMBERS + 1;
}

int main ( void ) {

	int bullet, chamber;	
	int turn = 1;

	char player1[50];
	char player2[50];

	printf( "Player 1 Name: " );
	scanf( "%49s", player1 );

	printf( "Player 2 Name: " );
	scanf( "%49s", player2 );

	srand( time(0) );	/* Initialize random number generator */
	
	bullet = rand() % CHAMBERS + 1;	/* place the bullet a random chamber */

	while( turn <= TURNS ) {

		printf( "\n\n --- Round %d ---\n", turn );

		/* Player1's turn */
		chamber = spinPull( player1 ); 
		// printf( "Bullet is %d, Chamber is %d\n", bullet, chamber );

		if ( chamber == bullet ) {
			printf( "BANG!!!\n" );
			printf( "%s. You\'re Dead! %s. You win!!\n", player1, player2 );
			exit( 1 );
		} else {
			printf( "Click.\n" );
		}

		/* Player2's turn */
		chamber = spinPull( player2 ); 
		// printf( "Bullet is %d, Chamber is %d\n", bullet, chamber );

		if ( chamber == bullet ) {
			printf( "BANG!!!\n" );
			printf( "%s. You\'re Dead! %s. You win!!\n", player2, player1 );
			exit( 1 );
		} else {
			printf( "Click.\n" );
		}

		turn++;
	}

	printf( "Everybody Wins!!\n" ); 
}
