/*
 * Simple pi using Newton's method
 *
 * Loosely based on examples found around the web
 *
 * compile with:
 *		gcc -03 -o pi pi.c
 *
 * (c) 2015 Derrik Walker v2.0
 * This is licensed for use under the GNU General Public License v2
 *
 * 2015/03/01	dwalker		Initial Version
 * 2022-09-05	dwalker		Updated for c99 compliance
 *
 */

#include "stdio.h"  
#include "stdlib.h"  
      
#define NO	2800
#define SCALE	10000  
#define A	2000  
      
int main( void ) {  

	int carry = 0;  
	int a[NO + 1];
	int i,j;

	for ( i = 0; i <= NO ; ++i)  
		a[i] = A;  

	for ( i = NO ; i > 0; i-= 14) {  

		int sum = 0;  

		for ( j = i; j > 0; --j) {  
			sum = sum * j + SCALE * a[j];  
			a[j] = sum % (j * 2 - 1);  
			sum /= j * 2 - 1;  
		}  

		// printf( "%d + %d / %d = ", carry, sum, SCALE );
		printf("%04d", carry + sum / SCALE);  

		carry = sum % SCALE;  
		//printf( " %d \n",carry );
	}  
	
	printf( "\n" );
}  
