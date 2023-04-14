#
# A simple makefile for managing build of project composed of C source files.
#


# It is likely that default C compiler is already gcc, but explicitly
# set, just to be sure
CC = gcc

# The CFLAGS variable sets compile flags for gcc:
#  -g        compile with debug information
#  -Wall     give verbose compiler warnings

CFLAGS = -g  -Wall -Werror -Wextra -pedantic
LDFLAGS = -lm

main: libAgenda2.o main.o
	$(CC) main.o libAgenda2.o -o tp2  $(LDFLAGS)

main.o : main.c	
	$(CC) $(CFLAGS) -c main.c

libAgenda2.o : libAgenda2.c
	$(CC) $(CFLAGS) -c libAgenda2.c

clean :
	rm *.o tp2

