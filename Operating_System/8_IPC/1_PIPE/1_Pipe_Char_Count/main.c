#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#define MAX_SIZE 65535
int main()
{
int fd[2];
int fdr,count=0;
char str[MAX_SIZE];
char buff[MAX_SIZE];
if(pipe(fd))
{
	perror("Unable to Create Pipe");
	exit(EXIT_FAILURE);
}
 fdr  = open("/usr/include/stdio.h",O_RDONLY);
if(-1==fdr)
{
	perror("Unable to open file");
	exit(EXIT_FAILURE);
}
pid_t id = fork();
if(0==id)
{
	close(fd[1]);
	read(fd[0],str,MAX_SIZE);
	close(fd[0]);
	int i = 0;
	int length = strlen(str);
	while(i!=length)
	{
		if(str[i]=='S')
		{
			count++;
		}
		i++;
	}
	printf("Count : %d\nLength : %ld",count,strlen(str));
}
else
{
	close(fd[0]);
	if(read(fdr,buff,MAX_SIZE)==-1)
	{
		perror("Unable to Read from library");
		exit(EXIT_FAILURE);
	}
	if(write(fd[1],buff,strlen(buff))==-1)
	{
		perror("Unable to Write to Pipe");
		exit(EXIT_FAILURE);
	}
	close(fd[1]);
	wait(NULL);
	
}
	return 0;

}
