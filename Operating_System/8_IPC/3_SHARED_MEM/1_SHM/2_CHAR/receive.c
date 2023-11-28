#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>

#define MAX 100

int main()
{
	char *count;
	char name[MAX];
	int fd = shm_open("/shared_region",O_RDWR,S_IRWXU);
	// To set he size of the object file
	//ftruncate(fd,sizeof(char)*MAX);
	count = (char *)mmap(NULL,sizeof(char)*MAX,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	read(fd,name,MAX);
	//strcpy(name,count);
	printf("%s\n",name);
	munmap(count,sizeof(char)*MAX );
	//sleep(10);
	return 0;
}

