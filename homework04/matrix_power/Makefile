CC=gcc

NAME=matrix
CFLAGS= -fopenmp -c -Wall -O3


all: $(NAME)

$(NAME): main.o matrix_lib.a
	$(CC) -fopenmp main.o matrix_lib.a -o $(NAME)

main.o: main.c
	$(CC) $(CFLAGS) main.c

matmul.o: matmul.c
	$(CC) $(CFLAGS) matmul.c

matrix_lib.a: matmul.o
	ar rcs matrix_lib.a matmul.o

clean:
	rm -rf *.o *.a $(NAME)
