#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5

pthread_mutex_t forks[NUM_PHILOSOPHERS]; // Mutexes for the forks
pthread_t philosophers[NUM_PHILOSOPHERS]; // Philosopher threads

void* philosopher(void* id) {
    int philosopherId = *((int*)id);

    while (1) {
        printf("Philosopher %d is thinking.\n", philosopherId);
        sleep(rand() % 3); // Simulate thinking time

        // Pick up left fork
        pthread_mutex_lock(&forks[philosopherId]);
        printf("Philosopher %d picked up left fork.\n", philosopherId);

        // Pick up right fork
        pthread_mutex_lock(&forks[(philosopherId + 1) % NUM_PHILOSOPHERS]);
        printf("Philosopher %d picked up right fork.\n", philosopherId);

        // Eating
        printf("Philosopher %d is eating.\n", philosopherId);
        sleep(rand() % 3); // Simulate eating time

        // Put down right fork
        pthread_mutex_unlock(&forks[(philosopherId + 1) % NUM_PHILOSOPHERS]);
        printf("Philosopher %d put down right fork.\n", philosopherId);

        // Put down left fork
        pthread_mutex_unlock(&forks[philosopherId]);
        printf("Philosopher %d put down left fork.\n", philosopherId);
    }
    return NULL;
}

int main() {
    // Initialize mutexes for each fork
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_init(&forks[i], NULL);
    }

    // Create philosopher threads
    int philosopherIds[NUM_PHILOSOPHERS];
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        philosopherIds[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &philosopherIds[i]);
    }

    // Join philosopher threads (not reachable in this infinite loop example)
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(philosophers[i], NULL);
    }

    // Destroy mutexes
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_destroy(&forks[i]);
    }

    return 0;
}