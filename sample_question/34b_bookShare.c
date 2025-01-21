#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void book(int reader){
  printf("Book is being borrowed by reader %d\n", reader);
}

void *friendFunc(int r){
  while(1){
    pthread_mutex_lock(&mutex);
    book(r);
    pthread_mutex_unlock(&mutex);
  }
}

int main(void){
  pthread_t t1, t2,t3,t4,t5;
  int v1=1,v2=2,v3=3,v4=4,v5=5;
  pthread_create(&t1, NULL, friendFunc, (void *)&v1);
  pthread_create(&t2, NULL, friendFunc, (void *)&v2);
  pthread_create(&t3, NULL, friendFunc, (void *)&v3);
  pthread_create(&t4, NULL, friendFunc, (void *)&v4);
  pthread_create(&t5, NULL, friendFunc, (void *)&v5);
  return 0;
}