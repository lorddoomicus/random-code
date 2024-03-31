/*
 * Simple pi using Newton's method
 *
 * Loosely based on examples found around the web
 *
 * compile with:
 *	Mac/Linux:
 *		gcc -03 -o pi pi.c
 *
 *	Amiga:
 *		vc -c99 +aos68k -o pi pi.c -lamiga -lauto
 *
 * (c) 2015 Derrik Walker v2.0
 * This is licensed for use under the GNU General Public License v2
 *
 * 2015-03-01	dwalker		Initial Version
 * 2022-09-05	dwalker		Updated for c99 compliance
 * 2024-03-31	dwalker		Fixed so it will run on an Amiga
 *
 */

#include <stdio.h>
#include <stdlib.h>
      
//#define NO	2800		// This one works for Mac or Linux
#define NO	500		// Required for this to run on the Amiga without crashing.
#define SCALE	10000  
#define A	2000  
      
int main( void ) {  

	int carry = 0;  
	int a[NO + 1];

	for ( int i = 0; i <= NO  ; ++i)
	 	a[i] = A;  

	for ( int i = NO ; i > 0; i-= 14) {  

		int sum = 0;  

		for ( int j = i; j > 0; --j) {  
		 	sum = sum * j + SCALE * a[j];  
		 	a[j] = sum % (j * 2 - 1);  
		 	sum /= j * 2 - 1;  
		}  

		printf("%04d", carry + sum / SCALE);  
		carry = sum % SCALE;  
	}  

	printf( "\n" );

}
