CC = gcc
main: main.o add.o sub.o mul.o div.o
	$(CC) -o main main.o add.o sub.o mul.o div.o
add.o:
	$(CC) -c add.c
sub.o:
	$(CC) -c sub.c
div.o:
	$(CC) -c div.c
mul.o:
	$(CC) -c mul.c
clear:
	rm -rf *.o main main.o
exe:
	$(CC) -o lib.so add.o mul.o sub.o div.o -shared -fPIC	
	$(CC) main.c lib.so
