/*
 * Takes an arbitrary integer for input and calculate an factorial using GMP
 * This was written as a little test program while learning GMP.
 *
 * Compiling this requires the GNU multiple precision arithmetic library version 6 or higher.
 *
 * compile with:
 *		gcc -lgmp -O3 -o factorial factorial.c
 *
 * (c) 2014 Derrik Walker v2.0
 * This is licensed for use under the GNU General Public License v2
 *
 * 2014-12-10	dwalker		Initial version
 * 2015-05-20	dwalker		Added error checking
 * 2022-04-09	dwalker		Added include for string.h and fixed c99 compliance
 */

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <string.h>

void usage( void );

int main( int argc, char** argv ) {

	int n;
	char *ender;
	mpz_t facto;  

	if ( argc != 2 )
		usage(); 

	n = strtol( argv[1], &ender, 10 );

	if ( ( n  < 0 ) || strcmp( ender, "\0" ) )
		usage();


	mpz_init( facto );

/*	if( argc != 2 ) { 
		printf( "%s", &usage );
		exit( 1 );
	} 


	n = atoi( argv[1] );
*/

	mpz_fac_ui( facto, n );		/* facto = n! */
	
	gmp_printf( "%Zd\n", facto );
} 

void usage () {
	printf( "Usage: factorial <number>\n" );
	printf( "\tWhere <number> is a positive integer and number >= 0 \n" );

	exit( 1 );
}
