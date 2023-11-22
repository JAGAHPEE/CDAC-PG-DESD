#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

//char *ptr = "/home/Desktop/Sandesh/C_Module/Code/file/a.txt";
int main()
{
	int fd =  open("a.txt", O_CREAT|O_RDWR,S_IRUSR|S_IWUSR);
	int a = write(fd, "Sandesh", 7);
	printf("%d",a);
	close(fd);


}
