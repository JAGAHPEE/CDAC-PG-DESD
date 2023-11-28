#include<stdio.h>
#include<semaphore.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	sem_t *semaphore;
	int *count;
	int fd = shm_open("/shared_memory", O_CREAT|O_RDWR,S_IRWXU);
	ftruncate(fd,sizeof(int));
	count = (int *)mmap(NULL,sizeof(int),PROT_READ|PROT_WRITE|PROT_EXEC,MAP_SHARED,fd,0);
	semaphore = sem_open("/shared_region", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	sem_init(semaphore,1,1);
//	sem_wait(semaphore);
//	*count = 0;
//	sem_post(semaphore);
	while(1)
	{
		sem_wait(semaphore);
//		(*count)++;
		printf("Count : %d\n",*count);
		//sleep(2);
		sem_post(semaphore);
		sleep(1);
	}
	return 0;
}

