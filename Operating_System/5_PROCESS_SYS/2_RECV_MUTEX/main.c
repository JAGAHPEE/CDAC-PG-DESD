#include<stdio.h>
#include<pthread.h>

pthread_mutex_t mutex1;
int count = 0;
pthread_mutexattr_t attrb;

void *increment(void *data)
{
    while(1)
    {
        pthread_mutex_lock(&mutex1);
        pthread_mutex_lock(&mutex1);
        count++;
        printf("Increment: %d\n",count);
        pthread_mutex_unlock(&mutex1);
        pthread_mutex_unlock(&mutex1);
    }
}
void *decrement(void *data)
{
    while (1)
    {
        pthread_mutex_lock(&mutex1);
        pthread_mutex_lock(&mutex1);
        count--;
        printf("Decrement: %d\n",count);
        pthread_mutex_unlock(&mutex1);
        pthread_mutex_unlock(&mutex1);
    }
    
}

int main()
{
    pthread_t inc_id,dec_id;
    pthread_create(&inc_id,NULL,increment,NULL);
    pthread_create(&dec_id,NULL,decrement,NULL);

    pthread_mutexattr_init(&attrb);
    pthread_mutexattr_settype(&attrb,PTHREAD_MUTEX_RECURSIVE_NP);
    pthread_mutex_init(&mutex1,&attrb);

    pthread_join(inc_id,NULL);
    pthread_join(dec_id,NULL);

    pthread_mutex_destroy(&mutex1);
    pthread_mutexattr_destroy(&attrb);
}