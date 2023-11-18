#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int fd = open("file1.txt",O_CREAT|O_RDWR,S_IWUSR|S_IRUSR);
	int byte = write(fd,"Sandesh Kale",12);
	close(fd);
}

