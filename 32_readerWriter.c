#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5
#define NUM_READERS 5
#define NUM_WRITERS 2

// Shared buffer and its variables
int buffer[BUFFER_SIZE];
int count = 0; // Number of items in the buffer
int readIndex = 0; // Index for reading from the buffer
int writeIndex = 0; // Index for writing to the buffer

// Semaphores for synchronization
sem_t readLock;   // Semaphore for readers
sem_t writeLock;  // Semaphore for writers
sem_t mutex;      // Mutex for protecting buffer access

// Function for reader threads
void* reader(void* id) {
    int readerId = *((int*)id);

    while (1) {
        sem_wait(&readLock); // Lock for reading
        sem_wait(&mutex);     // Lock the buffer

        if (count > 0) { // Check if there is data to read
            int data = buffer[readIndex];
            readIndex = (readIndex + 1) % BUFFER_SIZE; // Circular buffer
            count--;
            printf("Reader %d: Read data = %d\n", readerId, data);
        }

        sem_post(&mutex);     // Unlock the buffer
        sem_post(&readLock);  // Unlock for reading

        sleep(1); // Sleep after reading
    }
    return NULL;
}

// Function for writer threads
void* writer(void* id) {
    int writerId = *((int*)id);

    while (1) {
        sem_wait(&writeLock); // Lock for writing
        sem_wait(&mutex);     // Lock the buffer

        if (count < BUFFER_SIZE) { // Check if there is space to write
            buffer[writeIndex] = rand() % 100; // Write random data to buffer
            printf("Writer %d: Wrote data = %d\n", writerId, buffer[writeIndex]);
            writeIndex = (writeIndex + 1) % BUFFER_SIZE; // Circular buffer
            count++;
        }

        sem_post(&mutex);     // Unlock the buffer
        sem_post(&writeLock); // Unlock for writing

        sleep(1); // Sleep after writing
    }
    return NULL;
}

int main() {
    pthread_t readers[NUM_READERS], writers[NUM_WRITERS];
    int readerIds[NUM_READERS], writerIds[NUM_WRITERS];

    // Initialize semaphores
    sem_init(&readLock, 0, NUM_READERS); // Allow multiple readers
    sem_init(&writeLock, 0, 1);          // Only one writer at a time
    sem_init(&mutex, 0, 1);               // Mutex for buffer access

    // Create reader threads
    for (int i = 0; i < NUM_READERS; i++) {
        readerIds[i] = i + 1;
        pthread_create(&readers[i], NULL, reader, &readerIds[i]);
    }

    // Create writer threads
    for (int i = 0; i < NUM_WRITERS; i++) {
        writerIds[i] = i + 1;
        pthread_create(&writers[i], NULL, writer, &writerIds[i]);
    }

    // Join threads (this will not be reached in this infinite loop example)
    for (int i = 0; i < NUM_READERS; i++) {
        pthread_join(readers[i], NULL);
    }
    for (int i = 0; i < NUM_WRITERS; i++) {
        pthread_join(writers[i], NULL);
    }

    // Destroy semaphores
    sem_destroy(&readLock);
    sem_destroy(&writeLock);
    sem_destroy(&mutex);

    return 0;
}