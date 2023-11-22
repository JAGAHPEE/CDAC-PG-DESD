#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

int main(int argc,char*argv[])
{
	char ch;
	int fd = open(argv[1],O_CREAT|O_RDWR,S_IRUSR|S_IWUSR);
	ch = getchar();
	while(ch!='\n')
	{
		write(fd,&ch,1);
		ch = getchar();
	}
	close(fd);
	return 0;
	
}
