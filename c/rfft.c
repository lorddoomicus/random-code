/*
 * Calculates a Real FFT from a list of real
 *
 * compile with gcc -o rfft rfft.c -lgsl -lgslcblas -lm -O
 *
 * (c) 2016 Derrik Walker v2.0
 * This is licensed for use under the GNU General Public License v2
 *
 * 2016-09-19	dwalker		Initial Version
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <gsl/gsl_fft_real.h>

int main ( int argc, char *argv[] ) {

	double in, mag, freq;
	double *data = NULL;

	long n = 0;

	gsl_fft_real_wavetable * real;
	gsl_fft_real_workspace * work;

	int i, opts, rate=1;
	char *stop, *line = NULL;
	size_t len = 0U;
	ssize_t bla;
	
	opterr = 0; /* don't print option error messages */

        while (( opts = getopt( argc, argv, "hr:" )) != -1 )
		
		switch( opts ) {

			case 'r':
				rate = atoi ( optarg );

				if ( rate < 1 )
					//usage( NRML );
					printf( "ERRR!!\n" );

				break;
	
			case 'h':
				//usage( NRML );
				printf ( "Help!!\n" );
				return 0;
			
			default:
				printf( "ERRR!!\n" );
				return 0;
                }


	while (( bla = getline( &line, &len, stdin )) >= 0 ) {

		in = strtod( line, &stop );
		n ++;

		data = ( double * ) realloc ( data, n * sizeof( double ));

		if ( data == NULL ) {
			puts ( "Error (re)allocating memory" );
			exit ( 1 );
		}

		data[ n - 1 ] = in;
	}

	work = gsl_fft_real_workspace_alloc( n );
	real = gsl_fft_real_wavetable_alloc( n );

	gsl_fft_real_transform( data, 1, n, real, work );

	for ( i = 0 ; i < n - 1 ; i += 2 ) {
		
		freq = ( i/2 ) * (double)rate / n;
		mag =  2 * sqrt( data[i] * data[i] + data[i+1] * data[i+1] ) / n;
	
		printf( "%0.10f %0.14f\n", freq, mag );
	}

	gsl_fft_real_wavetable_free( real );
	gsl_fft_real_workspace_free( work );
	free( data );

	return 0;
}
