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
	printf("Enter String: ");
	char name[MAX];
	scanf("%[^\n]s",name);
	int fd = shm_open("/shared_region",O_CREAT|O_RDWR,S_IRWXU);
	ftruncate(fd,sizeof(char));
	count = (char *)mmap(NULL,sizeof(char)*strlen(name),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	write(fd,name,strlen(name));
	//sleep(10);
}

