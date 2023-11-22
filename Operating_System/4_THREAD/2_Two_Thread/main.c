#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
void *pf1(void*data)
{
	sleep(5);
	printf("Thread1\n");
}
void *pf2(void*data)
{	
	printf("Thread2\n");
}	
int main()
{
	pthread_t id1,id2;

	pthread_create(&id1,NULL,pf1, NULL);
	pthread_create(&id2,NULL,pf2, NULL);
	pthread_join(id1,NULL);
	pthread_join(id2,NULL);
	return 0;
}
