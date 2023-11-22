#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main()
{
char name[] = "Sandesh Kale";

char buff[sizeof(name)+1];
	int fd = open("file.txt",O_RDWR|O_CREAT,S_IRUSR|S_IWUSR);
	// printf("%d",fd);
	int byte = write(fd,name,strlen(name));
	printf("%d",byte);
	//close(fd);
	// Read from file
	//fd = open("file.txt",O_RDWR|O_CREAT,S_IRUSR|S_IWUSR);
	// Write to File1
	int fd2 = open("file1.txt",O_RDWR|O_CREAT,S_IRUSR|S_IWUSR);
	ssize_t a = read(fd,buff,byte);
	printf("%ld",strlen(buff));
	write(fd2,buff,byte);

	printf("%s",buff);
	close(fd);
	close(fd2);
}
