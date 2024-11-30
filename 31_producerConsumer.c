#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5  // Define the buffer size

int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;

// Semaphores
sem_t empty;
sem_t full;
pthread_mutex_t mutex;

// Producer function
void *producer(void *arg) {
    int item;
    while (1) {
        item = rand() % 100;  // Produce an item

        sem_wait(&empty);  // Decrease empty count
        pthread_mutex_lock(&mutex);  // Enter critical section

        // Add the item to the buffer
        buffer[in] = item;
        printf("Producer produced item %d at %d\n", item, in);
        in = (in + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex);  // Exit critical section
        sem_post(&full);  // Increase full count

        sleep(1);  // Simulate time delay
    }
    return NULL;
}

// Consumer function
void *consumer(void *arg) {
    int item;
    while (1) {
        sem_wait(&full);  // Decrease full count
        pthread_mutex_lock(&mutex);  // Enter critical section

        // Remove the item from the buffer
        item = buffer[out];
        printf("Consumer consumed item %d from %d\n", item, out);
        out = (out + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex);  // Exit critical section
        sem_post(&empty);  // Increase empty count

        sleep(1);  // Simulate time delay
    }
    return NULL;
}

int main() {
    pthread_t prod_thread, cons_thread;

    // Initialize the semaphores and mutex
    sem_init(&empty, 0, BUFFER_SIZE);  // Buffer has BUFFER_SIZE empty slots
    sem_init(&full, 0, 0);  // Buffer initially has 0 full slots
    pthread_mutex_init(&mutex, NULL);

    // Create producer and consumer threads
    pthread_create(&prod_thread, NULL, producer, NULL);
    pthread_create(&cons_thread, NULL, consumer, NULL);

    // Wait for the threads to finish
    pthread_join(prod_thread, NULL);
    pthread_join(cons_thread, NULL);

    // Destroy the semaphores and mutex
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}
