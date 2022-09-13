#
# (c) 2015 Derrik Walker v2.0
# This is licensed for use under the GNU General Public License v2
#
# 2015-04-27	dwalker		Initial Release
# 2020-06-13	dwalker		Updated to support brew on a Mac
# 2022-04-04	dwalker		Added support for M1 Macs
# 2022-09-05	dwalker		Added a bunch of programs
#

# Brew library and include locations for compiling on Macs
# Comment out for Linux systems
LIB_DIR=`brew --prefix`/lib
INC_DIR=`brew --prefix`/include

avg:
	gcc -O3 -lm -o avg avg.c

bits:
	gcc -O3 -o bits bits.c

coin:
	gcc -O3 -o coin coin.c 

combo:
	gcc -O3 -I$(INC_DIR) -L$(LIB_DIR) -lgmp -o combo combo.c

decomp:
	gcc -O3 -o decomp decomp.c

dice:
	gcc -O3 -o dice dice.c

dp:
	gcc -O3 -o dp dp.c

egypt:
	gcc -O3 -I$(INC_DIR) -L$(LIB_DIR) -lgmp -o egypt egypt.c

factorial:
	gcc -O3 -I$(INC_DIR) -L$(LIB_DIR) -lgmp -o factorial factorial.c

fibonacci:
	gcc -O3 -I$(INC_DIR) -L$(LIB_DIR) -lgmp -o fibonacci fibonacci.c

monty:
	gcc -O3 -o monty monty.c

pi:
	gcc -O3 -o pi pi.c

rfft:
	gcc -O3 -I$(INC_DIR) -L$(LIB_DIR) -lm -lgsl -lgslcblas -o rfft rfft.c 

spinner:
	gcc -O3 -o spinner spinner.c

all: 	avg bits coin combo decomp dice dp egypt factorial fibonacci monty pi rfft spinner

clean: 
	rm -f *.o core avg bits coin combo decomp dice dp egypt factorial fibonacci monty pi rfft spinner
