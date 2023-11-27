#include<stdio.h>
#include<semaphore.h>
#include<stdlib.h>
#include<pthread.h>
sem_t scan,cal;
int a,b,sum;
void *scann(void *data)
{
	while(1)
	{
		sem_wait(&scan);
		printf("\nEnter the 1 Number: ");
		scanf("%d",&a);
		printf("\nEnter the 2nd Number: ");
		scanf("%d",&b);
		sem_post(&cal);
	}
}
void *calculate(void *data)
{
	while(1)
	{
		sem_wait(&cal);
		sum  = a+b;
		printf("Sum : %d",sum);
		sem_post(&scan);

	}
	
}


int main()
{

	pthread_t scan_id,cal_id;
	
	sem_init(&scan,0,1);
	sem_init(&cal,0,0);
	pthread_create(&scan_id,NULL,scann,NULL);
	pthread_create(&cal_id,NULL,calculate,NULL);

	pthread_join(scan_id,NULL);
	pthread_join(cal_id,NULL);

	sem_destroy(&scan);
	sem_destroy(&cal);
	return 0;

}
