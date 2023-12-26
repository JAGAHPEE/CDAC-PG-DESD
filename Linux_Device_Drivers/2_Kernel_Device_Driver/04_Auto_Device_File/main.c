/*
 * Published by : Sandesh Kale
 * LinkedIn     : https://www.linkedin.com/in/sandesh-s-kale
 * github       : https://github.com/JAGAHPEE
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int fd = open("/dev/char_device_file",S_IRUSR|S_IRGRP|S_IROTH,O_RDWR);
	if(fd<0)
	{	
		printf("Unable to Open file\n");
		return -1;
	}
	close(fd);
}
