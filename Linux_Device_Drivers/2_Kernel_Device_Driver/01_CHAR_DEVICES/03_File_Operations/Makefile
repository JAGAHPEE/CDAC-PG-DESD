obj-m := char_driver_file.o
KDIR = /lib/modules/$(shell uname -r)/build/
all:
	make -C $(KDIR) M=$(PWD) modules
clean:
	make -C $(KDIR) M=$(PWD) clean
