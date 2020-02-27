CC=g++
CFLAGS=-I.
DEPS = patil-prathamesh.hpp

%.o: %.c $(DEPS)
	$(CC) -c -std=c++11 -o $@ $< $(CFLAGS)

hellomake: matOps.o 
	$(CC) -std=c++11 -o mat matOps.o
