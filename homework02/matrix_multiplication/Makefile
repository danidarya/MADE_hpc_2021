CC=gcc

OPT=
NAME=matrix
CFLAGS=-c -Wall ${OPT}


all: $(NAME)

$(NAME): main.o matrix_lib.a
	$(CC) main.o matrix_lib.a -o $(NAME)

main.o: main.c
	$(CC) $(CFLAGS) main.c

matmul.o: matmul.c
	$(CC) $(CFLAGS) matmul.c

matrix_lib.a: matmul.o
	ar rcs matrix_lib.a matmul.o

clean:
	rm -rf *.o *.a $(NAME)
