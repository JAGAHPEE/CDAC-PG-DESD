#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

#include"../headers.h"

#define DEVICE "/dev/device_file"

int main()
{
	int fd = open(DEVICE,O_RDWR,0777);
	if(fd<0)
	{
		printf("Unable to Open File\n");
		return 1;
	}	
	int result;
	printf("App2-> Read Data\n");
	ssize_t bytes_read = read(fd,&result,sizeof(result));
	if(bytes_read < 0)
	{
		printf("Unable to Read from the File\n");
	}
	else
	{
		printf("Result: %d",result);
	}
	close(fd);
	return 0;
}
