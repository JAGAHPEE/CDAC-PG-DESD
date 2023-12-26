/*
 * Published by : Sandesh Kale
 * LinkedIn     : https://www.linkedin.com/in/sandesh-s-kale
 * github       : https://github.com/JAGAHPEE
*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/ioctl.h>
#include"headers.h"

int main()
{
	int fd = open("/dev/GPIO_device_driver",O_RDWR),option = 0 ;
	if(fd<0)
	{
		printf("Unable to open file \n");
		return -1;
	}
	while(1)
	{
		printf("Press 1 for LED ON and 0 for LED OFF\n");
		scanf("%d",&option);
		if(option==1)
		{
			if(ioctl(fd,GPIO_SET_L,&option))
			{
				printf("Unable to Send Command\n");
			}
			else
			{
				printf("Command Sent\n");
			}
		}
		else if(option ==0)
		{
			if(ioctl(fd,GPIO_RESET_L,&option))
			{
				printf("Unable to Send Command\n");
			}
			else
			{
				printf("Command Sent\n");
			}
		}
		else
		{
			printf("Invalid Options\n");
		}		
	}				
	close(fd);
}

