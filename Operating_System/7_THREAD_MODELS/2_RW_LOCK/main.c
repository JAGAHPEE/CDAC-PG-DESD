#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
int err;
int count =0;
pthread_rwlock_t rw_lock;
void *read_l(void *data)
{
	while(1)
	{
		printf("\nRead Lock: 1\n");
		pthread_rwlock_rdlock(&rw_lock);	
		printf("Count: %d\n",count);
		pthread_rwlock_unlock(&rw_lock);
		printf("Unlock 1\n");
		sleep(1);
	}
}
void *write_l(void *data)
{

	while(1)
	{	printf("************write 1*******************\n");
		printf("\nWrite Lock: 1\n");
		pthread_rwlock_wrlock(&rw_lock);
		count+=1;
		printf("Count INC\n");
		pthread_rwlock_unlock(&rw_lock);
		printf("Write Unlock 1\n");
		sleep(5);

	}
}

void *write_l2(void *data)
{
        while(1)
        {
		printf("**********Write 2**************************\n");
                printf("\nWrite Lock: 2\n");
                pthread_rwlock_wrlock(&rw_lock);
                count+=1;
                printf("Count INC\n");
                pthread_rwlock_unlock(&rw_lock);
                printf("Write Unlock 2\n");
                sleep(5);

        }
}

void *read_l1(void *data)
{
        while(1)
        {

                printf("\nRead Lock: 1\n");
                pthread_rwlock_rdlock(&rw_lock);        
                printf("Count: %d\n",count);
                pthread_rwlock_unlock(&rw_lock);
                printf("Unlock 1\n");
                sleep(1);
        }
}

int main()
{
	pthread_t id1,id2,id3,id4;
	if((pthread_rwlock_init(&rw_lock,NULL)))
	{
		printf("Error Creating Lock\n");
	}
	
	if((pthread_create(&id1,NULL,read_l,NULL)))
	{
		printf("Unable to Create Thread\n");
	}
	if((pthread_create(&id2,NULL,write_l,NULL)))
	{
		printf("Unable to Create Thread\n");
	}
	 if((pthread_create(&id3,NULL,read_l1,NULL)))
        {
                printf("Unable to Create Thread\n");
        }
	if((pthread_create(&id4,NULL,write_l2,NULL)))
        {
                printf("Unable to Create Thread\n");
        }


	
	pthread_join(id1,NULL);
	pthread_join(id2,NULL);	
	pthread_join(id3,NULL);
	pthread_join(id4,NULL);
	pthread_rwlock_destroy(&rw_lock);

}
