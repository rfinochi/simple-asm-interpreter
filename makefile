CC=gcc
CFLAGS=-I.

smcmake: smc.c interpreter.h interpreter.c io.h io.c screen.h screen.c
	$(CC) -o smc.out smc.c interpreter.c io.c screen.c $(CFLAGS)