CC=gcc
CFLAGS=-I.

smcmake: smc.c interpreter.h interpreter.c screen.h screen.c
	$(CC) -o smc.out smc.c interpreter.c screen.c $(CFLAGS)