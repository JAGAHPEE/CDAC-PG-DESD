#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc,char *argv[])
{

	//int m = mkfifo("/home/dj/Desktop/PROCESS/2_FIFO/pipes",0600);
	int fd = open("pipes",O_WRONLY);
	if(-1==fd)
	{
		printf("Unable to Open File\n");
		//exit(EXIT_FAILURE);
	}

	write(fd,argv[1],strlen(argv[1]));
	close(fd);
	
	return 0;



}
