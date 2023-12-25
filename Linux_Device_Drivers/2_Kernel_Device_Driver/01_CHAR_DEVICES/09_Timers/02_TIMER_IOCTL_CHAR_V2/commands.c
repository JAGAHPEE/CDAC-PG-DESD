#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/ioctl.h>

#include"headers.h"
char data = 0;
#define FILE "/dev/char_device_file"

int main()
{

	int fd = open(FILE,O_RDWR);
	if(fd<0)
	{
		printf("Unable to Open File\n");
		return 0;
	}
	if(ioctl(fd,IO_RD,&data))
	{
		printf("Unable to Send Command\n");
		close(fd);
		return 0;
	}
	printf("Command Sent Successfully\n");
	close(fd);
	return 0;
}
	
