/*
 * sizeof.c
 *
 * This is an old program that I wrote many years ago that prints information
 * about the c-variable types.
 *
 * compile with:
 *               gcc -o sizeof sizeof.c
 *
 * (c) 2015 Derrik Walker v2.0
 * This is licensed for use under the GNU General Pulbic License v2
 *
 * 2015-05-04	dwalker		Initial Release
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define BITS 8

int main( void )
{
	int x = 1;
	char sys[80]; 
 	FILE *fp;
	struct pointer { void *ptr; };

  	fp = popen( "/usr/bin/uname  -p -r -s", "r" );

	if (fp == NULL) {

		printf("Failed to run command\n" );
		exit(1);
	}

	fgets( sys, sizeof(sys), fp );

	pclose( fp );

	printf( "System: %s\n", sys ); 
	
	printf( "Byte Order: ");
	
	if( *(char *) & x == 1)	/* Will break with weird byte ordering */

		printf("little-endian\n\n");
	else	
		printf("big-endian\n\n");


	printf( "\n\ttype \t # of bits\n" );
	printf( "\t-------------------\n" );
	printf( "\tchar: \t\t%d\n",	BITS * ( int ) sizeof( char ));
 	printf( "\tdouble: \t%d\n",	BITS * ( int ) sizeof( double ));
	printf( "\tfloat: \t\t%d\n",	BITS * ( int ) sizeof( float ));
	printf( "\tint: \t\t%d\n",	BITS * ( int ) sizeof( int ));
	printf( "\tunsigned int:\t%d\n",BITS * ( int ) sizeof( unsigned int ));
	printf( "\tlong: \t\t%d\n",	BITS * ( int ) sizeof( long ));
	printf( "\tlong double: \t%d\n",BITS * ( int ) sizeof( long double ));
	printf( "\tpointer:\t%d\n",	BITS * ( int ) sizeof( struct pointer ));
	// printf( "\tushort \t\t%d\n", sizeof( ushort ));
	
	printf( "\n" );

	return 0;
}
