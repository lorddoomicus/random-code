/*
 * Calculates the average, standard deviation, max and minimum of numbers
 * entered one per line, via STDIN.  This can be used as a filter, and the
 * only limit to the number of numbers is the available memory
 *
 * compile with:
 *		gcc -O3 -lm -o avg avg.c
 *
 * (c) 2012 Derrik Walker v2.0
 * This is licensed for use under the GNU General Public License v2
 *
 * 2012-11-12	dwalker		Initial version
 * 2015-01-27	dwalker		Added command line options
 * 2025-02-24	dwalker		Fixed a bug that made it ignore 0 as a min
 *				Print the Sum as well.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define NAME	"avg"
#define NRML	0
#define SPR	1

#define OFF	0
#define ON	1

void usage( int type );

int main( int argc, char *argv[] ) {

	float	data;

	float	max = 0, min = -1;
	double	avg, sum = 0;
	double	v, std_dev;

	long	count = 0;
	float	*nos = NULL;

	int	max_flag = OFF, min_flag = OFF, sum_flag = OFF;
	int	avg_flag = OFF, std_dev_flag = OFF; 
	int	all_flag = ON;

	int	i, opts;
	char	*stop, *line = NULL;
	size_t	len = 0U;
	ssize_t	n;


	/*
	 * Process the cmd args 
	 */

	opterr = 0; /* don't print option error messages */

	while (( opts = getopt( argc, argv, "HhamiSs" )) != -1 )
	
		switch( opts ) {

			case 'a':
				avg_flag = ON;	
				all_flag = OFF;
				break;

			case 'm':
				max_flag = ON;	
				all_flag = OFF;
				break;

			case 'i':
				min_flag = ON;	
				all_flag = OFF;
				break;

			case 's':
				std_dev_flag = ON;
				all_flag = OFF;
				break;

			case 'S':
				sum_flag = ON;
				all_flag = OFF;
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
				return 0;
		}
	
	/*
	 * Main program Processing
	 */

	while (( n = getline( &line, &len, stdin )) >= 0 ) {

		data = strtof( line, &stop );
	
		sum += data;
		count++;

		nos = ( float* ) realloc( nos, count * sizeof( float ));

		if ( nos == NULL ) { 
			puts ( "Error (re)allocating memory" ); 
			exit ( 1 ); 
		}
		nos[ count - 1 ] = data;

		if( min < 0 || data <= min ) { min = data; }

		if( data > max ) { max = data; }
	}
	
	avg = sum / count;

	for( i = 0; i < count; i++ ) 
		v += pow( nos[i] - avg, 2 );

	std_dev=sqrt( v / count );		

	/*
	 * Printout the results
	 */

	if( avg_flag == ON )
		printf( "%f\n", avg );

	if( max_flag == ON )
		printf( "%f\n", max );	

	if( min_flag == ON )
		printf( "%f\n", min );	

	if( std_dev_flag == ON )
		printf( "%f\n", std_dev );

	if( sum_flag == ON )
		printf( "%f\n", sum );

	if( all_flag == ON ) {

		printf( "\n    Sum: %f\n", sum );
		printf( "    Min: %f\n", min );
		printf( "    Max: %f\n", max );
		printf( "    Avg: %f\n", avg );
		printf( "Std Dev: %f\n\n", std_dev );
	}
}

void usage( int type ) {

	printf ( "Usage: %s", NAME ); 
	printf ( " [-h|H][-a][-m][-i][-S][-s]\n" );

	if( type == SPR ) {	/* extended help */
		printf ( "\nWhere:\n" );
		printf ( "\t-h: simple help\n" );
		printf ( "\t-H: super help\n" );
		printf ( "\t-a: print just the average\n" );
		printf ( "\t-m: print just the max\n" );
		printf ( "\t-i: print just the min\n" );
		printf ( "\t-s: print just the std variation\n" );
		printf ( "\t-S: print just the sum\n" );

		printf ( "\nNotes:\n" ); 
		printf ( "\t- one number per line on STDIN\n" );
		printf ( "\t- can be used as a filter\n" );
		printf ( "\t- no args prints all the above\n" );
		printf ( "\t- input can be any valid C double type\n" );
	}

	exit( 1 );
}

