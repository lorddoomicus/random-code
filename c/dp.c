/*
 * A little program to test the c compiler on a computer
 *
 * compile with:
 *		gcc -O3 -o dp dp.c
 *
 * (c) 1998 Derrik Walker v2.0
 * This is licensed for use under the GNU General Public License v2
 *
 * 1998-??-?? 	dwalker		initial version
 * 2022-09-05	dwalker		Updated for c99 compliance
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {

	if (argc > 1 && strcmp(argv[1], "-advice") == 0) {
		printf("Don't Panic!\n");
		exit(42);
	}
}
