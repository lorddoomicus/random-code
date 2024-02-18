#
# (c) 2015 Derrik Walker v2.0
# This is licensed for use under the GNU General Public License v2
#
# 2015-04-27	dwalker		Initial Release
# 2020-06-13	dwalker		Updated to support brew on a Mac
# 2022-04-04	dwalker		Added support for M1 Macs
# 2022-09-05	dwalker		Added a bunch of programs
# 2024-02-17	dwalker		Added a cc var and changed to use clang	
#				Added russian
#

# Brew library and include locations for compiling on Macs
# Comment out for Linux systems
LIB_DIR=`brew --prefix`/lib
INC_DIR=`brew --prefix`/include

# C compiler
CC=clang
 
avg:
	$(CC) -O3 -lm -o avg avg.c

bits:
	$(CC) -O3 -o bits bits.c

coin:
	$(CC) -O3 -o coin coin.c 

combo:
	$(CC) -O3 -I$(INC_DIR) -L$(LIB_DIR) -lgmp -o combo combo.c

decomp:
	$(CC) -O3 -o decomp decomp.c

dice:
	$(CC) -O3 -o dice dice.c

dp:
	$(CC) -O3 -o dp dp.c

egypt:
	$(CC) -O3 -I$(INC_DIR) -L$(LIB_DIR) -lgmp -o egypt egypt.c

factorial:
	$(CC) -O3 -I$(INC_DIR) -L$(LIB_DIR) -lgmp -o factorial factorial.c

fibonacci:
	$(CC) -O3 -I$(INC_DIR) -L$(LIB_DIR) -lgmp -o fibonacci fibonacci.c

monty:
	$(CC) -O3 -o monty monty.c

pi:
	$(CC) -O3 -o pi pi.c

rfft:
	$(CC) -O3 -I$(INC_DIR) -L$(LIB_DIR) -lm -lgsl -lgslcblas -o rfft rfft.c 

russian:
	$(CC) -O3 russian.c -o russian

sizeof:
	$(CC) -O3 -o sizeof sizeof.c	

spinner:
	$(CC) -O3 -o spinner spinner.c

all: 	avg bits coin combo decomp dice dp egypt factorial fibonacci monty pi rfft russian sizeof spinner

clean: 
	rm -f *.o core avg bits coin combo decomp dice dp egypt factorial fibonacci monty pi russian rfft sizeof spinner
