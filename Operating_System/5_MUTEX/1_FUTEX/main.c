#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
int sum=0;
// Create a Mutex Variable for  Lock and Unlock Critical Section
pthread_mutex_t mutex_1;

void increment(void *data)
{
	while(1)
	{
		pthread_mutex_lock(&mutex_1);
		sum++;
		printf("Increment: %d\n",sum);
		pthread_mutex_unlock(&mutex_1);
		//sleep(1);
	}	
}

void decrement(void *data)
{
	while(1)
	{	
		pthread_mutex_lock(&mutex_1);
		sum--;
		printf("Decrement: %d\n",sum);
		pthread_mutex_unlock(&mutex_1);
		//sleep(1);
		
	}
}
int main()
{
	pthread_t id1,id2;
	pthread_mutex_init(&mutex_1,NULL);
	pthread_create(&id1,NULL,(void *)increment,NULL);
	pthread_create(&id2,NULL,(void *)decrement,NULL);
	pthread_join(id1,NULL);
	pthread_join(id2,NULL);
	
	pthread_mutex_destroy(&mutex_1);

}
