CC = gcc

all: main

main: main.o menu.o
	$(CC) $(CFLAGS) -lm -o tp main.o menu.o

menu.o: menu.c biblioteca.h
	$(CC) $(CFLAGS) -lm -c biblioteca.h menu.c

clean:
	rm -rf tp main.o menu.o
