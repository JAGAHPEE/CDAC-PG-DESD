#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
int sum=0;
void *runner(void *data)
{
	int i,upper=atoi(data);
	sum=0;
	for(i=1;i<=upper;i++)
	{
		sum =sum+i;
	}
	pthread_exit(0);

}
int main(int argc, char *argv[])
{
	pthread_t id;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_create(&id,&attr,runner,argv[1]);
	pthread_join(id,NULL);
	printf("Sum : %d\n",sum);
	pthread_attr_destroy(&attr);
}	
