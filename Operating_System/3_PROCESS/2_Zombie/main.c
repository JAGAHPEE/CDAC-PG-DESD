#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	pid_t id;
	printf("---Before fork\n");
	id = fork();
	if(0==id)
	{
		printf("Child: PID: %d PPID: %d\n",getpid(),getppid());
		exit(0);
	}
	else
	{
		printf("Parent: %d PPID : %d\n",getpid(),getppid());
		sleep(10);
	}

	return 0;


}

