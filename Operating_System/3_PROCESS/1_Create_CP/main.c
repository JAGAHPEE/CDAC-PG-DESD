#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
	//printf("Before Fork........\n");
	//printf("Parent Process ID: %d\n",getppid());
	//printf("Child Process ID:%d\n",getpid());
	
	// Creating new child Process using fork
	fork();
	//printf("After Fork..\n");
	//printf("Parent Process ID: %d\n",getppid());
	//printf("Child Process ID: %d\n",getpid());

	fork();
	//After Second Fork
	//printf("After 2nd Fork\n");
	//printf("Parent Process ID: %d\n",getppid());
	//printf("Child Process ID: %d\n",getpid());
	
	fork();
	//printf("After fork 3\n");
	printf("Parent Process ID: %d\n",getppid());
	printf("Child Process ID: %d\n",getpid());
}
