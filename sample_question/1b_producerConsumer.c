#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>

#define  BUFFERSIZE 5
#define PRODUCER 3
#define CONSUMER 3

int buffer[BUFFERSIZE];
int in=0, out=0;

sem_t empty, full;
pthread_mutex_t mutex;

void *producer(void *arg){
  int id = *((int *)arg);
  while (1){
    int item=rand() % 100;
    sem_wait(&empty);
    pthread_mutex_lock(&mutex);

    buffer[in]=item;
    printf("Producer %d: Inserting item %d at %d\n", id, item, in);
    in= (in + 1)%BUFFERSIZE;

    pthread_mutex_unlock(&mutex);
    sem_post(&full);
    sleep(1);
    
  }
}

void *consumer(void *arg){
  int id = *((int *)arg);
  while(1){
    sem_wait(&full);
    pthread_mutex_lock(&mutex);
    int item = buffer[out];
    printf( "Consumer %d: Removing item %d from %d\n", id, item, out);
    out = (out + 1)%BUFFERSIZE;
    pthread_mutex_unlock(&mutex);
    sem_post(&empty);
    sleep(1);
  }
}

int main(void){
  pthread_t prodThreads[PRODUCER], consThreads[CONSUMER];
  int ids[PRODUCER> CONSUMER? PRODUCER:CONSUMER];
  
  pthread_mutex_init(&mutex, NULL);
  sem_init(&empty, 0, BUFFERSIZE);
  sem_init(&full, 0, 0);

  for (int i = 0; i<PRODUCER; i++){
    ids[i] = i+1;
    pthread_create(&prodThreads[i], NULL, producer, &ids[i]);
  }
  for (int i = 0; i<CONSUMER; i++){
    ids[i] = i+1;
    pthread_create(&consThreads[i], NULL, consumer, &ids[i]);
  }

  for (int i = 0; i<PRODUCER; i++){
    pthread_join(prodThreads[i], NULL);
  }
  for (int i = 0; i<CONSUMER; i++){
    pthread_join(consThreads[i], NULL);
  }
  return 0;
}