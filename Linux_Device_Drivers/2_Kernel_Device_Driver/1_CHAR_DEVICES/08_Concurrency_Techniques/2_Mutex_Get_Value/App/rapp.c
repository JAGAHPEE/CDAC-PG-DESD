#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int fd = open("/dev/Char_device_file",O_RDWR,0777);
	int num=0;
	if(fd<0)
	{
		printf("Unable to open File\n");
		return 1;
	}
	ssize_t bytes  = read(fd,&num,sizeof(num));
	if(bytes<0)
	{
		printf("Unable to Read from file\n");
	}
	else
	{
		printf("Data Read from file: %d\n",num);
	}
	close(fd);
	return 0;
}
