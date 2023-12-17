#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/ioctl.h>
#include<unistd.h>
#include"headers.h"
int main()
{
	struct my_data data = {"Sandesh Kale",10};
	int fd = open("/dev/ioctl_driver",O_RDWR);
	if(fd<0)
	{
		printf("Unable to Open File\n");
		return -1;
	}
	printf("Command 1\n");
	ioctl(fd,ONE);
	printf("Command 2\n");
	ioctl(fd,TWO);
	printf("Command 3\n");
	ioctl(fd,THREE);
	printf("Command IO_W\n");
	ioctl(fd,IO_W,&data);
	close(fd);
}
