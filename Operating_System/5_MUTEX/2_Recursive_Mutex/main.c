#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
/* In mutex dual lock will create a deadlock conditon to avoid this \
use recursive mutex .

IN this create mutexattr attribute and mutex variable

initialise mutex variable 

mutexattr_init((&attr)
mutexattr_settype(&attr,PTHREAD_MUTEX_RECURSIVE_NP)
pthread_mutex_init(&mutex_1)

*/
pthread_mutexattr_t attr;
pthread_mutex_t mutex_1;
int sum=0;


void decrement(void *data)
{
	while(1)
	{
		pthread_mutex_lock(&mutex_1);
		pthread_mutex_lock(&mutex_1);	
		sum++;
		printf("Increment: %d\n",sum);
		pthread_mutex_unlock(&mutex_1);
                pthread_mutex_unlock(&mutex_1); 
	}
}
void increment(void *data)
{

	 while(1)
        {
                pthread_mutex_lock(&mutex_1);
                pthread_mutex_lock(&mutex_1);   
                sum--;
                printf("Decrement: %d\n",sum);
                pthread_mutex_unlock(&mutex_1);
                pthread_mutex_unlock(&mutex_1); 
        }

}
int main(int argc , char * argv[])
{

	int sum =atoi(argv[1]);
	pthread_t id1,id2;
	pthread_mutexattr_init(&attr);
	pthread_mutexattr_settype(&attr,PTHREAD_MUTEX_RECURSIVE_NP);
	pthread_mutex_init(&mutex_1,&attr);
	

	pthread_create(&id1,NULL,(void*)increment,NULL);
	pthread_create(&id2,NULL,(void*)decrement,NULL);
	

	pthread_join(id1,NULL);
	pthread_join(id2,NULL);
	pthread_mutexattr_destroy(&attr);
	pthread_mutex_destroy(&mutex_1);

}
