#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>


int main()
{
	int *count;
	// Create or Open the Shared File
	int fd = shm_open("/shared",O_CREAT|O_RDWR,S_IRWXU);

	// Type of Allocation
	ftruncate(fd,sizeof(int));

	// Map file or device to Memory
	// Address:  NULL << address allocated by kernal
	// Length : sizeof(int) <<length of Memory
	// Prot   : PORT_READ | PROT_WRITE <<Protection
	// flag   : MAP_SHARED <<update  will be visible to all
	// offset : 0 << from where to start <starting Location
	// (int *): type of memoey allocated should be of int as similar to malloc typecase
	count = (int *)mmap(NULL,sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);

	//*count = 0;
	while(1)
	{
		(*count)++;
		printf("Count Updated\n");
		sleep(1);
	}
	return 0;


}
