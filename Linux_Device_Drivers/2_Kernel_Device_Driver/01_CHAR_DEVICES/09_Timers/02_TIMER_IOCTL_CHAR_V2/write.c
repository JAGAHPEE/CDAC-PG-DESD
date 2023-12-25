#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/ioctl.h>

#include"headers.h"
#define FILE "/dev/char_device_file"

int main()
{
	struct my_data data;
	int fd = open(FILE,O_RDWR);
	if(fd<0)
	{
		printf("Unable to Open File\n");
		return 0;
	}
	printf("ENter Data to Insert:\n");
	printf("Enter Name: ");
	scanf("%[^\n]s",data.name);

	printf("Enter Roll Number: ");
	scanf("%d",&data.rollno);
	
	if(ioctl(fd,IO_WR,&data))
	{
		printf("Unable to Send Command\n");
		close(fd);
		return 0;
	}
	printf("Command Sent Successfully\n");
	close(fd);
	return 0;
}
	
