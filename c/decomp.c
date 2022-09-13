/* 
 * Decomposes integers into their powers of two components
 *
 * compile with:
 * 		gcc -03 -o decomp decomp.c
 *
 * (c) 2014 Derrik Walker v2.0
 * This is licensed for use under the GNU General Public License v2
 *
 * 2014-05-14	dwalker		Initial Version
 * 2022-09-05	dwalker	 	updated for c99 compliance
 */

#include <stdio.h>
#include <stdlib.h>

int main( int argc, char** argv ) {
	int num = 0, a = 1; 
	char usage[] = "Usage: %s <number> where 0 > number < 1073741823\n";

	if( argc != 2 ) { 
		printf( "%s", usage );
		exit( 1 );
	}

	num = atoi( argv[1] );

	if( num > 1073741823 ) {
		printf ( "%s", usage );
		exit( 1 );
	}

	while( num > 0 ) { 

		while( a <= num )  a *= 2;
 
		a /= 2;

		printf( "%i\n", a );

		num = num - a;
		a = 1;
	}
}
