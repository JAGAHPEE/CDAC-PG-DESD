#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

pthread_cond_t condition;
pthread_mutex_t mutex;
int check = 0;
void *send(void *data)
{
	printf("Setting Lock 1\n");
	pthread_mutex_lock(&mutex);
	printf("Mutex Lock 1\n");
	while(!check)
	{
		// Waiting for the Signal
		printf("Waiting\n");
		pthread_cond_wait(&condition,&mutex);
		printf("Wait End\n");
	}
	check  = 0;
	printf("Signal Received\n");
	pthread_mutex_unlock(&mutex);
	printf("Mutex unlock 1\n");
}

void *receive(void *data)
{

	printf("\n\nSetting Lock 2\n");
	pthread_mutex_lock(&mutex);
	printf("Mutex Lock 2\n");
	printf("Sleeping Thread 2\n");
	sleep(5);
	// Signaling the Thread 1 to get unlock
	pthread_cond_signal(&condition);
	check = 1;
	printf("Signal Send\n");
	pthread_mutex_unlock(&mutex);
	printf("Mutex unlock 2\n");	
}

int main()
{
	pthread_t id1,id2;
	// For Initializing Mutual Exclusion
	pthread_mutex_init(&mutex,NULL);
	// For Initialization of Conditional Variable
	pthread_cond_init(&condition,NULL);

	pthread_create(&id1,NULL,send,NULL);
	pthread_create(&id2,NULL,receive,NULL);


	pthread_join(id1,NULL);
	pthread_join(id2,NULL);
	// Destroying mutex and conditional variable
	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&condition);
	
	return 0;

}
