CC=gcc

NAME=pagerank
CFLAGS= -fopenmp -c -Wall -O3


all: $(NAME)

$(NAME): pagerank.o matrix_lib.a
	$(CC) -fopenmp pagerank.o matrix_lib.a -o $(NAME)

pagerank.o: pagerank.c
	$(CC) $(CFLAGS) pagerank.c

matmul.o: matmul.c
	$(CC) $(CFLAGS) matmul.c

matrix_lib.a: matmul.o
	ar rcs matrix_lib.a matmul.o

clean:
	rm -rf *.o *.a $(NAME)
