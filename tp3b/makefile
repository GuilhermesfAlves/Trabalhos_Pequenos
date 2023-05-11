# Makefile de exemplo (Manual do GNU Make)
     
CFLAGS = -Wall -std=c90 -g  # flags de compilacao
LDFLAGS = -lm

CC = gcc

# arquivos-objeto
	objects = main.o libpilhapar.o 
     
all: main.o libpilhapar.o
	$(CC) -o main main.o libpilhapar.o $(LDFLAGS)

libpilhapar.o: libpilhapar.c
	$(CC) -c $(CFLAGS) libpilhapar.c

main.o: main.c
	$(CC) -c $(CFLAGS) main.c

clean:
	rm -f $(objects) main