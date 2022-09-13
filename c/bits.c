/*
 * Converts an integer to binary bits
 *
 * compile with:
 *		gcc -O3 -o bits bits.c
 *
 * (c) 2014 Derrik Walker v2.0
 * This is licensed for use under the GNU General Public License v2
 *
 * 2014-05-21 	dwalker		Initial version
 * 2022-09-05	dwalker		Updated for c99 compliance 
 */

#include <stdio.h>
#include <stdlib.h>

int main ( int argc, char** argv ){
	int i, num, bit;

	if( argc != 2 ){
		printf( "ERRR!!!!\n" ); 
		exit( 1 );
	}

	num = atoi( argv[1] );

	do { 
		bit = num & 1;
		num = num >> 1;

		printf( "%d", bit );

	} while( num > 0 );
		
	printf( "\n" );
}
