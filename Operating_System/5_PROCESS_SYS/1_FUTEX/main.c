#include<pthread.h>
#include<stdio.h>

pthread_mutex_t mutex_1;
int count = 0;

void *increment(void *data)
{
    while (1)
    {
        pthread_mutex_lock(&mutex_1);
        count++;
        printf("Increment: %d\n",count);
        pthread_mutex_unlock(&mutex_1);
    }
}

void *decrement(void*data)
{
    while (1)
    {
        pthread_mutex_lock(&mutex_1);
        count--;
        printf("Decrement: %d\n",count);
        pthread_mutex_unlock(&mutex_1);
    }
    
}
int main()
{
    pthread_t inc_id,dec_id;
    pthread_mutex_init(&mutex_1,NULL);
    
    // Create Thread for Increment:
    pthread_create(&inc_id,NULL,increment,NULL);
    pthread_create(&dec_id,NULL,decrement,NULL);
    pthread_join(inc_id,NULL);
    pthread_join(dec_id,NULL);
    pthread_mutex_destroy(&mutex_1);


}