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
	printf("Enter the Number to Write:");
	scanf("%d",&num);
	ssize_t bytes  = write(fd,&num,sizeof(num));
	if(bytes<0)
	{
		printf("Unable to Write to file\n");
	}
	close(fd);
	return 0;
}
