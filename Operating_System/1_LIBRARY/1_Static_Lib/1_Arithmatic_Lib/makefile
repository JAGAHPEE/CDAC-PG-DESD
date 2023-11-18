CC = gcc
main: main.o add.o sub.o mul.o div.o
	$(CC) -o main main.o add.o mul.o sub.o div.o
add.o:
	$(CC) -c add.c
sub.o:
	$(CC) -c sub.c
mul.o:
	$(CC) -c mul.c
div.o:
	$(CC) -c div.c
archieve:
	ar crv arith_library.a *.o
clear:
	rm -rf *.o a.out

