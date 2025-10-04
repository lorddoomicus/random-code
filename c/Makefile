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
# 2026-10-04	dwalker		Updated to build in Solaris 10


# This is for gcc or clang

# MacOS 
# LIB_DIR=`brew --prefix`/lib
# INC_DIR=`brew --prefix`/include
# C_OPTS=-03
# cc=clang

# Linux
# C_OPTS=-03 -m64
# CC=gcc

# Solaris
LIB_DIR=/opt/csw/lib/64
INC_DIR=/opt/csw/include
C_OPTS=-xarch=v9
CC=cc
 
avg:
	$(CC) $(C_OPTS) -lm -o avg avg.c

bits:
	$(CC) $(C_OPTS) -o bits bits.c

coin:
	$(CC) $(C_OPTS) -o coin coin.c 

combo:
	$(CC) $(C_OPTS) -I$(INC_DIR) -L$(LIB_DIR) -R$(LIB_DIR) -lgmp -o combo combo.c

decomp:
	$(CC) $(C_OPTS) -o decomp decomp.c

dice:
	$(CC) $(C_OPTS) -o dice dice.c

dp:
	$(CC) $(C_OPTS) -o dp dp.c

egypt:
	$(CC) $(C_OPTS) -I$(INC_DIR) -L$(LIB_DIR) -R$(LIB_DIR) -lgmp -o egypt egypt.c

factorial:
	$(CC) $(C_OPTS) -I$(INC_DIR) -L$(LIB_DIR) -R$(LIB_DIR) -lgmp -o factorial factorial.c

fibonacci:
	$(CC) $(C_OPTS) -I$(INC_DIR) -L$(LIB_DIR) -R$(LIB_DIR) -lgmp -o fibonacci fibonacci.c

monty:
	$(CC) $(C_OPTS) -o monty monty.c

pi:
	$(CC) $(C_OPTS) -o pi pi.c

rfft:
	$(CC) $(C_OPTS) -I$(INC_DIR) -L$(LIB_DIR) -R$(LIB_DIR) -lm -lgsl -lgslcblas -o rfft rfft.c 

russian:
	$(CC) $(C_OPTS) -o russian russian.c

sizeof:
	$(CC) $(C_OPTS) -o sizeof sizeof.c	

spinner:
	$(CC) $(C_OPTS) -o spinner spinner.c

all: 	avg bits coin combo decomp dice dp egypt factorial fibonacci monty pi rfft russian sizeof spinner

clean: 
	rm -f *.o core avg bits coin combo decomp dice dp egypt factorial fibonacci monty pi russian rfft sizeof spinner
