CC=g++
CFLAGS=-g -Wall
OBJS=example.o cargs.o
TARGET=example

cargs.o: cargs.c cargs.h

example: example.c cargs.o cargs.h
	$(CC) -o example example.c cargs.o

clean:
	rm -rf *.o
	rm $(TARGET)