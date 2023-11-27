#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>
sem_t semaphore;
int count;

void *increment(void *data)
{
	while(1)
	{
		sem_wait(&semaphore);
		count++;
		printf("Increment : %d\n",count);	
		sem_post(&semaphore);
	}
}

void *decrement(void *data)
{
	while(1)
        {
                sem_wait(&semaphore);
                count--;
                printf("Decrement : %d\n",count); 
                sem_post(&semaphore);
        }

}
int main(int argc, char *argv[])
{
	pthread_t id1,id2;
	count = atoi(argv[1]);
	// sem_init(  variable  ,  shared between thread , Initial value 1 sempost
	// Binary Semaphore has only two value 0 and 1	
	sem_init(&semaphore,0,1);
	pthread_create(&id1,NULL,increment,NULL);
	pthread_create(&id2,NULL,decrement,NULL);

	pthread_join(id1,NULL);
	pthread_join(id2,NULL);

	sem_destroy(&semaphore);
	return 0;
}
