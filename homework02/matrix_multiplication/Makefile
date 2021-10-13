CC=gcc

CFLAGS=-c -Wall -g

all: matrix

matrix: main.o matrix_lib.a
	$(CC) main.o matrix_lib.a -o matrix

main.o: main.c
	$(CC) $(CFLAGS) main.c

matmul.o: matmul.c
	$(CC) $(CFLAGS) matmul.c

matrix_lib.a: matmul.o
	ar rcs matrix_lib.a matmul.o

clean:
	rm -rf *.o *.a matrix
