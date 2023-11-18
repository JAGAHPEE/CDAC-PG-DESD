#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>
int main()
{
//char *name  = "Sandesh Kale";
	char name[20];
	int fd1 = open("file1.txt",O_RDWR|O_CREAT,S_IRUSR|S_IWUSR);
	//int byte = write(fd1,name,strlen(name));
	int fd2 = open("file2.txt",O_RDWR|O_CREAT,S_IRUSR|S_IWUSR);
	ssize_t bytes = read(fd1,name,12);
	int byte = write(fd2,name,strlen(name));
	printf("%s",name);
	close(fd2);
	close(fd1);
}
