#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char*argv[])
{
	if(argc<3)
	{
		printf("File name not defined");
		exit(-1);
	}
	int fd_s = open(argv[1],O_RDONLY,S_IRUSR|S_IWUSR);
	if(fd_s<0)
	{
		printf("Unable to open Source File");
		exit(1);
	}
	int fd_d = open(argv[2],O_CREAT|O_RDWR,S_IRUSR|S_IWUSR);
	if(fd_d<0)
	{	
		printf("Unable to create Destination File");
		exit(1);
	}
	char buff[10];
	int in,out;
	while ((in = read(fd_s, buff, 10)) > 0)
	{
		out = write(fd_d, buff, in);
		if (out != in)
		{
		    perror("Error copying");
		}
	}
	close(fd_s);
	close(fd_d);
	

}
