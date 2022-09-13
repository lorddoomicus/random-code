/*
 * Demonstrates multiplication by the method described in the Rhind Papyrus.
 * This is the method used by the ancient Egyptians.
 *
 * Compiling this requires the GNU multiple precision arithmetic library version 6 or higher.
 *
 * compile with:
 *		gcc -lgmp -O3 -o egypt egypt.c
 *
 * (c) 2009 Derrik Walker v2.0
 * This is licensed for use under the GNU General Public License v2
 *
 * 2009-04-09	dwalker		Initial Version
 * 2015-05-12	dwalker		Rewrote to use GMP so it can handle numbers of any size                                           *
 */

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int main( int argc, char** argv ) {

	mpz_t x, y, a, b, t1, t2;

	mpz_init( x );
	mpz_init( y );
	mpz_init( a );
	mpz_init( b );
	mpz_init( t1 );
	mpz_init( t2 );

	if ( argc == 3 ) {

		mpz_set_str (  x, argv[1], 0 );
		mpz_set_str (  y, argv[2], 0 );

	} else { 

		printf( "Usage: argv[0] x y where x & y are ints\n" );
		exit( 1 );
	}

	printf( "\n" );
	
	mpz_set_ui( a, 1 );
	
	while ( mpz_cmp( a, x ) <= 0  ) {

		gmp_printf( "%20Zd %20Zd", a, y );
	
		/* the gmp version of "if (( a & x ) == a  )" ...  */

		mpz_and( b, a, x);		/* b = ( a & x ) */

		if ( mpz_cmp( b, a ) == 0 ) {	/* if ( b == a ) */

			mpz_add( t1, t1, a );	/* t1 += a */
			mpz_add( t2, t2, y );	/* t2 += y */
		
			printf ( "\t\\" );	 
		} 
			

		printf( "\n" );

		mpz_mul_ui( a, a, 2 ); 	/* a *= 2; */
		mpz_mul_ui( y, y, 2 ); 	/* y *= 2; */
	}

	printf ( "--------------------------------------------------------\n" );
	gmp_printf( "%20Zd %20Zd\n\n", t1, t2 );

	return( 0 );
			
}
