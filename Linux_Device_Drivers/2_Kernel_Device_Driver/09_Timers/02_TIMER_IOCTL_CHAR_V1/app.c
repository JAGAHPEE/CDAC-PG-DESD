#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/ioctl.h>
#include"headers.h"

#define FILE_NAME "/dev/char_device_file"
int main()
{
	int fd = open(FILE_NAME,O_RDWR);
	if(fd<0)
	{
		printf("Unable to Open File\n");
		return 1;
	}
	int data;
	
	int option;
	while(1)
	{
		printf("Enter the Options: ");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				if(!ioctl(fd,SET_TIME,&data))
				{
					printf("Sent Set_Time Command\n");
				}	
				break;
			case 2:
				if(!ioctl(fd,READ_C,&data))
				{		
					printf("Sent Read Command Command\n");
				}
				break;

			case 3:
				if(!ioctl(fd,WRITE_C,&data))
				{
					printf("Sent Write Command\n");
				}
				break;
			case 4:
				if(!ioctl(fd,DEBUG_FLAG_C,&data))
				{
					printf("Sent Debug_flag Command\n");
				}
				break;
			case 5:
				if(!ioctl(fd,LED_ON,&data))
				{
					printf("Sent LED Command\n");
				}
				break;
			case 6:
				if(!ioctl(fd,LED_OFF,&data))
				{
					printf("Sent Set_Time Command\n");
				}
				break;
			case 10:
				close(fd);
				return 0;
		}
	}
	close(fd);
	return 0;
}


