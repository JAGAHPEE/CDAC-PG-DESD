#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 5
#define N_ITEMS 10

int buffer[BUFFER_SIZE];
pthread_mutex_t mutex;
sem_t full, empty;

int in = 0;
int out = 0;

void *producer(void *arg) {
    int item;

    for (int i = 0; i < N_ITEMS; ++i) {
        item = rand() % 100;

        sem_wait(&empty);
        pthread_mutex_lock(&mutex);

        buffer[in] = item;
        in = (in + 1) % BUFFER_SIZE;

        printf("Producer produced item %d at index %d\n", item, in);

        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }

    return NULL;
}

void *consumer(void *arg) {
    int item;

    for (int i = 0; i < N_ITEMS; ++i) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);

        item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;

        printf("Consumer consumed item %d at index %d\n", item, out);

        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }

    return NULL;
}

int main() {
    pthread_t prod, cons;
    
    // Initialize mutex and semaphores
    pthread_mutex_init(&mutex, NULL);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, BUFFER_SIZE);

    // Create producer and consumer threads
    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    // Wait for threads to finish
    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    // Cleanup
    pthread_mutex_destroy(&mutex);
    sem_destroy(&full);
    sem_destroy(&empty);

    printf("All items are produced and consumed\n");

    return 0;
}
