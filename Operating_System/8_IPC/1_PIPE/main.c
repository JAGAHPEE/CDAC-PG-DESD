#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
int main(int argc, char *argv[])
{
	int fd[2];
	pid_t cpid;
	char buf;
	 if(pipe(fd)==-1)
        {
                perror("Pipe not Created\n");
                exit(EXIT_FAILURE);
        }
	cpid = fork();
	if(cpid==-1)
	{
		perror("Unable to Create Process\n");
		exit(EXIT_FAILURE);
	}
	if(cpid==0)
	{
		close(fd[1]);
		while(read(fd[0],&buf,1)>0)
		{
			//printf("%c",buf);
			write(STDOUT_FILENO,&buf,1);
		}
		printf("\nData Received\n");
		close(fd[0]);
	}
	else
	{
		close(fd[0]);
		write(fd[1],argv[1],strlen(argv[1]));
		printf("Data Sent\n");
		close(fd[1]);
		wait(NULL);
		exit(EXIT_SUCCESS);
	}
	
}
