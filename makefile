CC = gcc
CFLAGS = -Wall -Werror -Wextra
AG = agenda

all: main.o libAgenda.o
	$(CC) -o agenda main.o libAgenda.o

libAgenda.o: libAgenda.c
	$(CC) $(CFLAGS) -c libAgenda.c

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o $(AG)
