obj-m := Led_Timer_Ioctl_Driver.o
KDIR = /lib/modules/$(shell uname -r)/build
all:
	make -C $(KDIR) M=$(PWD) modules
	gcc app.c -o app
clean:
	make -C $(KDIR) M=$(PWD) clean
	rm -r app
