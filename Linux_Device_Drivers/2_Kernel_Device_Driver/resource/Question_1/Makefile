obj-m := Device_file.o
KDIR = /lib/modules/$(shell uname -r)/build
default:
	make -C $(KDIR) M=$(PWD) modules
	gcc write.c -o write
	gcc read.c -o read
	gcc ioctl.c -o ioctl_file
clean:
	make -C $(KDIR) M=$(PWD) clean
	rm write ioclt_write read
