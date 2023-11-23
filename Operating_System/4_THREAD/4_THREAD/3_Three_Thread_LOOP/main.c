#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
 

void *pf1(void*data)
{
	int i=0;
	while(i<5)
	{	
		i++;
		printf("Thread 1: %d\n",i);
	}
}
void *pf2(void*data)
{
	int i=0;
	while(i<5)
	{
		i++;
		sleep(5);
		printf("Thread 2: %d\n",i);	
	}
}
int main()
{
	pthread_t id1,id2;
	pthread_create(&id1,NULL,pf1,NULL);
	pthread_create(&id2,NULL,pf2,NULL);
	pthread_join(id1,NULL);
	pthread_join(id2,NULL);
	return 0;

}
