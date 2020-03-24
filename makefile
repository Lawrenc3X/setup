CC = gcc
CXX = g++
CFLAGS = -g
CXXFLAGS = -g

setup: setup.c 
	$(CC) $(CFLAGS) -o setup setup.c

all: setup.c 
	$(CC) $(CFLAGS) -o setup setup.c

clean:
	rm -r setup setup.dSYM
