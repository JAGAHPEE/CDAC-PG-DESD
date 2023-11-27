#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#define BUFF 4096
int main(int argc, char *argv[])
{
	int fd = open("pipes",O_RDONLY);
	char buff[BUFF];
	read(fd, buff,BUFF);
	printf("%s",buff);
	close(fd);
	printf("\n");
	return 0;
}
