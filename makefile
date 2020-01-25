CC = gcc
FLAGS = -Wall -g
MAIN = TRIE.o 

all: frequency 
TRIE.o: TRIE.c TRIE.h
	$(CC) $(FLAGS) -g -c TRIE.c
frequency: TRIE.o
	$(CC) $(FLAGS) -o frequency TRIE.o
.PHONY: clean all
clean:
	rm -f *.o *.a *.so frequency
