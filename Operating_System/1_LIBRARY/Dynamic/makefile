CC = gcc
OBJECTS = main.o add.o sub.o read.o
LIBRARY = libarithmatic.so  # Changed to .so for shared library
TARGET = main

all: $(TARGET) $(LIBRARY)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^

main.o: main.c
	$(CC) -c $<

add.o: add.c
	$(CC) -c $<

sub.o: sub.c
	$(CC) -c $<

read.o: read.c
	$(CC) -c $<

$(LIBRARY): $(OBJECTS)
	$(CC) -o $@ $(OBJECTS) -shared -fPIC

clear:
	rm -rf *.o $(TARGET) $(LIBRARY) lib.so a.out

#exp:
#	#export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(pwd)
