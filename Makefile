CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -Werror
all: determinant
determinant: main.o matrix.o
	$(CC) $(CFLAGS) -o determinant main.o matrix.o
main.o: main.c matrix.h
	$(CC) $(CFLAGS) -c main.c
matrix.o: matrix.c matrix.h
	$(CC) $(CFLAGS) -c matrix.c
clean:
	rm -f determinant main.o matrix.o