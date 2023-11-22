#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	pid_t id;
	int a = 0;
	printf("Before Fork\n");
	id = fork();
	if(0==id)
	{
		printf("Child: PID: %d PPID: %d\n",getpid(),getppid());
		sleep(10);
//                int a;
//                scanf("%d",&a);
//                printf("%d",a);

		printf("Child: PID: %d PPID: %d\n",getpid(),getppid());
	}
	else
	{
		printf("Parent: %d PPID : %d\n",getpid(),getppid());
		//exit(0);
                //scanf("%d",&a);
                //printf("%d",a);
	
	}
	return 0;
}
