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
		return 0;
	}	
	struct my_data data;
	printf("App1-> Enter value a & b : ");
	scanf("%d %d",&data.a,&data.b);
	write(fd,&data,sizeof(struct my_data));
	close(fd);
}
