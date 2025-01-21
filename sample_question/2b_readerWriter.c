#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

#define READER 5
#define WRIITER 2

int shared_data=0;
int reader_cnt=0;

pthread_mutex_t mutex;
sem_t resource;

void *reader(void *arg){
  int id = *((int *)arg);
  while(1){
    pthread_mutex_lock(&mutex);
    read_cnt++;
    if(read_cnt==1){
      sem_wait(&resource);
    }
    pthread_mutex_unlock(&mutex);

    pthread_mutex_lock(&mutex);
    printf("Reader %d is reading shared data: %d\n", id, shared_data);
    read_cnt--;
    if(read_cnt==0){
      sem_post(&resource);
    }
    pthread_mutex_unlock(&mutex);
    sleep(1);
  }
}

void *writer(void *arg){
  int id = *((int *)arg);
  while(1){
    sem_wait(&resource);

    shared_data=rand()%100;
    printf("Writer %d writes shared data: %d\n", id, shared_data);
    
    sem_post(&resource);

    sleep(1);
  }
}

int main(void){
  pthread_t readerThreads[READER], writerThreads[WRITER];
  int ids[READER>WRITER?READER:WRITER];

  pthread_mutex_init(&mutex, NULL);
  sem_init(&resource, 0, 1);

  for(int i = 0; i<READER; i++){
    ids[i]=i+1;
    pthread_create(&readerThreads[i], NULL, reader, &ids[i]);
  }
  for(int i = 0; i<WRITER; i++){
    ids[i]=i+1;
    pthread_create(&writerThreads[i], NULL, writer, &ids[i]);
  }
  for(int i = 0; i<READER; i++){
    pthread_join(readerThreads[i], NULL);
  }
  for(int i = 0; i<WRITER; i++){
    pthread_join(writerThreads[i]);
  }

  return 0;
}