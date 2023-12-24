/*
 * Published by : Sandesh Kale
 * LinkedIn     : https://www.linkedin.com/in/sandesh-s-kale
 * github       : https://github.com/JAGAHPEE
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/ioctl.h>
#include"headers.h"

int main()
{
	int fd = open("/dev/IOCTL_DRIVER",O_RDWR),timeout;
	if(fd<0)
	{
		printf("Unable to open Device File\n");
		return -1;
	}
	while(1)
	{
		printf("Enter time Timeout value for LED\n");
		scanf("%d",&timeout);
		if(timeout==1)
		{
			break;
		}
		if(ioctl(fd, IOCTL_W, &timeout)<0)
		{
			printf("Unable to Send Command\n");
			close(fd);
			return -1;
		}
	}
	close(fd);
	return 0;
}

