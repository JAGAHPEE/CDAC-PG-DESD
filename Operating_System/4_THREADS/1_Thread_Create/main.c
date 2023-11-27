#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
void *pf(void *data)
{
	int i=0;
	while(i<3)
	{	
		i++;
		printf("Thread is Executing\n");
	}
	return NULL;
}
int main()
{
	
	pthread_t id_t;
	printf("Before Thread\n");
	pthread_create(&id_t,NULL,pf,NULL);
	pthread_join(id_t,NULL);
	printf("After Thread\n");
	return 0;
}
