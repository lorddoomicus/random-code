/*
 * Computes combinations and permutations for arbitrary integers
 *
 * When run with -c ( default ) this will calculate the combinations:
 *
 * 	    /n\
 * Computes \k/, that is combinations of k from n.
 *
 * When run -p, it will calculate the  permutations:
 *
 * 	    /n\
 * Computes \k/, that is permutations of k from n.
 *
 * Compiling this requires the GNU multiple precision arithmetic library
 * version 6 or higher.
 *
 * compile with:
 *	 gcc -lgmp -03 -o combo combo.c
 *
 * (c) 2014 Derrik Walker v2.0
 * This is licensed for use under the GNU General Pulbic License v2
 *
 * 2014-12-10	dwalker		Initial version
 * 2014-12-30	dwalker		Added permutations
 * 2015-05-28	dwalker		Added super help and error checking
 * 2022-09-05	dwalker		Updated for c99 compliance
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <gmp.h>

#define COMBO	0
#define PERM	1

#define NAME "combo"
#define NRML	0
#define SPR	1

void usage( int type ); 

int main( int argc, char** argv ) {

	int n, k, mode;
	mpz_t answer, bn, bk, bnk, bknk; 
	char *ender;

	if( argc == 2 ) {
	
		if ( strcmp( argv[1], "-H" ) == 0 )
			usage( SPR );

		else
			usage( NRML );

		exit( 1 );
	}

	if( argc == 3 ) {
		mode = COMBO;

		n = strtol( argv[1], &ender, 10 );
		k = strtol( argv[2], &ender, 10 );

	}

	else if( argc == 4) {

		if ( strcmp( argv[1], "-c" ) == 0 )
			mode = COMBO;

		else if( strcmp( argv[1], "-p" ) == 0 )
			mode = PERM;

		else {
			usage( NRML );	
			exit( 1 );
		}

		n = strtol( argv[2], &ender, 10 );
		k = strtol( argv[3], &ender, 10 );

	} else {
			usage( NRML );	
			exit( 1 );
	}

	if ( ( n < 1 ) || ( k < 1 ) || ( n < k ) || strcmp( ender, "\0" ) ) {

		usage( NRML );
		exit( NRML );
	}

	mpz_init( answer );	/* the answer we want */
	mpz_init( bn );		/* gmpized n */
	mpz_init( bk);		/* gmpized k */
	mpz_init( bnk );	/* gmpized n - k */
	mpz_init( bknk );	/* gmpized k! - (n - k)! */ 

	/* 
	 *	if combinations:
	 *		answer = n! / k! * ( n - k )! 
  	 *	
	 * 	if permutations:
	 *		answer = n! / ( n - k )!
	 *
	 *	Either way, it has to be calculated in steps do to the way 
	 *	gmp works ... 
	 */

	mpz_fac_ui( bn, n );			/* n! */
	mpz_fac_ui( bk, k );			/* k! */
	mpz_fac_ui( bnk, n - k );		/* (n - k)! */

	if ( mode == COMBO ) {

		mpz_mul( bknk, bk, bnk );	/* k! * (n - k)! */

		mpz_cdiv_q( answer, bn, bknk );	/* n! / ( k! * (n - k)! ) */

	} else if ( mode == PERM ) {

		mpz_cdiv_q( answer, bn, bnk );	/* n! / (n - k)! */

	} else {
		printf ( "ERRR!!!\n" ); 
		exit( 2 );
	}
	
	gmp_printf( "%Zd\n", answer );

}

void usage( int type ) {

	char usage[] = "Usage: combo [-c|-p] n k \n"; 
	printf ( "usage: %s", NAME ); 
	printf ( " [-h|-H] [-c|-p] n k, n > k \n" );  

	if( type == SPR ) {	/* super help */
		printf ( "\nWhere:\n" );
		printf ( "\t-h: simple help\n" );
		printf ( "\t-H: super help\n" );
		printf ( "\t-c: calculates the combinations of n from k\n" );
		printf ( "\t-p: calculates the permutaitons of n from k\n" );

                printf ( "\nNotes:\n" );
                printf ( "\t- combinations ( -c ) is the default\n" );
                printf ( "\t- all the input values must be integers > 0\n" );
                printf ( "\t- n > k\n" );
	}
}
