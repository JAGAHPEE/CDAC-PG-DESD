CC = gcc
OBJECT =  main.o add.o sub.o read.o
LIBRARY = libarithmatic.a
TARGET = main
LINK = static
DYNAMIC = dynamic
all:$(TARGET)
$(TARGET):main.o $(OBJECT)
	$(CC) -o $@ $^
main.o:main.c
	$(CC) -c $^
add.o:add.c
	$(CC) -c $^
sub.o:sub.c
	$(CC) -c $^
read.o:read.c
	$(CC) -c $^
$(LIBRARY):
	ar crv $@ add.o sub.o read.o

$(LINK): main.c $(LIBRARY)
	$(CC) $< -L. -larithmatic -o $(LINK)
clear:
	rm -rf *.o  a.out $(TARGET) $(LIBRARY)
$(DYNAMIC):$(OBJECT)
	$(CC) -o lib.so $^ -shared -fPIC
exp: 
	export LD_LIBRARY_PATH=~/Desktop/PROCESS/prectice/2_Library/
