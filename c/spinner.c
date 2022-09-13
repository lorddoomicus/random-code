/*
 * Simple animated spinner - no real value for anything 
 *
 * compile with:
 *		gcc -O3 -o spinner spinner.c
 *
 * (c) 2015 Derrik Walker v2.0
 * This is licensed for use under the GNU General Public License v2
 *
 * 2015-01-20	dwalker		Initial version
 * 2022-09-05	dwalker		Updated for c99 compliance
 */

#include <stdio.h>
#include <unistd.h>

// #define DELAY	10000	/* 100 ms */
#define DELAY	25000		/* 25 ms */
// #define DELAY	50000	/* 60 ms */
// #define DELAY	100000	/* 100 ms */

int main( void ) {

	int i;
	char spinny[] = {'|', '/', '-', '\\'};

	while ( 1 ) 

		for( i = 0; i < 4; i++ ) {

			printf( "\r%c", spinny[i] );

			fflush( stdout ); 
			usleep( DELAY ); 
		}
}
