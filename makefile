CC = gcc
CXX = g++
CFLAGS = 
CXXFLAGS = 

setup: setup.c
	$(CC) $(CFLAGS) -o setup setup.c

all: setup.c
	$(CC) $(CFLAGS) -o setup setup.c

clean:
	rm -r setup setup.dSYM
