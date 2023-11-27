#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

pthread_barrier_t barrier;

void *temp(void *data)
{
	printf("Temperature Barrier\n");
	sleep(3);
	pthread_barrier_wait(&barrier);
	printf("Temperature\n");
}
void *lcd(void *data)
{
        printf("LCD Barrier\n");
       	sleep(1);
	 pthread_barrier_wait(&barrier);
        printf("LCD\n");
}
void *wifi(void *data)
{
        printf("WIFI Barrier\n");
	sleep(5);
        pthread_barrier_wait(&barrier);
        printf("WIFI\n");
}
void *eth(void *data)
{
        printf("ETH Barrier\n");
	sleep(7);
        pthread_barrier_wait(&barrier);
        printf("ETH\n");
}

int main()
{
	pthread_t id1,id2,id3,id4;
	pthread_barrier_init(&barrier,NULL,4);
	if((pthread_create(&id1,NULL,temp,NULL)))
	{
		printf("Unable to create Thread\n");
	}
	if((pthread_create(&id2,NULL,lcd,NULL)))  
        {
                printf("Unable to create Thread\n");
        }
	if((pthread_create(&id3,NULL,wifi,NULL)))  
        {
                printf("Unable to create Thread\n");
        }
	if((pthread_create(&id4,NULL,eth,NULL)))  
        {
                printf("Unable to create Thread\n");
        }

	pthread_join(id1,NULL);
	pthread_join(id2,NULL);
	pthread_join(id3,NULL);
	pthread_join(id4,NULL);
	pthread_barrier_destroy(&barrier);
}
