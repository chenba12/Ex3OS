CC = gcc
CFLAGS = -Wall -g
.PHONY: all clean
all: isort txtfind

isort: isort.o
	$(CC) $(CFLAGS) isort.o -o isort -lm

txtfind: txtfind.o
	$(CC) $(CFLAGS) txtfind.o -o txtfind -lm
clean:
	rm -f  isort txtfind *.o
