#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>
int main()
{
	char *name;
	int fd = open("file1.txt",O_RDWR,S_IRUSR|S_IWUSR);
	ssize_t a = read(fd ,name,10);
	printf("%ld",a);
	printf("%s",name);
	int fd1 = open("file_copy.txt",O_CREAT,S_IRUSR|S_IWUSR);
	write(fd1,name,strlen(name));
	close(fd);
	close(fd1);
}
