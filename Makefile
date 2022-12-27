CC = gcc
CFLAGS = -Wall -g
.PHONY: all clean
all: isort txtfind

txtfind.o: txtfind.c
	$(CC) $(CFLAGS) -c txtfind.c

isort: isort.o
	$(CC) $(CFLAGS) isort.o -o isort

txtfind: txtfind.o
	$(CC) $(CFLAGS) txtfind.o -o txtfind -lm
clean:
	rm -f  isort txtfind *.o
