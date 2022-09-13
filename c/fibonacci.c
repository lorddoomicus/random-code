/*
 * Takes one integer as an input n, and prints all the fibonacci numbers from  F(0) to F(n).
 *
 * Compiling this requires the GNU multiple precision arithmetic library version 6 or higher.
 *
 * compile with:
 *		gcc -lgmp -O3 -o fibonacci fibonacci.c
 *
 * (c) 2015 Derrik Walker v2.0
 * This is licensed for use under the GNU General Public License v2
 *
 * 2015-01-17	dwalker		Initial version
 * 2015-05-15	dwalker		Added error checking
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

void usage( void );

int main( int argc, char ** argv ) {

	int i, n;
	char *ender;
	mpz_t a, b, c; 

	if ( argc != 2 )
		usage(); 

	n = strtol( argv[1], &ender, 10 );

	if ( ( n  < 1 ) || strcmp( ender, "\0" ) )
		usage();

	/* printf( "n = %d\n", n ); */

/*
 * Start with first 3: 0 1 1 ...
 */
	for( i=1; i < 3 ; i++ ) {

		printf("%d\n", i - 1 );

		 if ( n == 1 )
		 	exit( 0 ); 
	}
	
	if( n < 3 ) 
		exit( 0 );

/*
 * if n => 3, then use gmp and start computing 
 */	
	mpz_init( a );
	mpz_init( b );
	mpz_init( c );

	mpz_set_ui( a, 0 );
	mpz_set_ui( b, 1 );

	for( i = 3; i<=n; i++ ) {

		mpz_add( c, a, b );	/* c = a + b 	*/
		mpz_set( a, b );	/* a = b	*/
		mpz_set( b, c );	/* b = c	*/

		gmp_printf( "%Zd\n", c );
	}

	exit( 0 );
}

void usage () {

	printf( "Usage: fibonacci <number>\n" );
	printf( "\tWhere <number> is a positive integer and number > 0 \n" );
	exit( 1 );
}
