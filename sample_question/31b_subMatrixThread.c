#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>

pthread_mutex_t mutex1=PTHREAD_MUTEX_INITIALIZER;
int a[2][2], b[3][3];

void *func1(){
  pthread_mutex_lock(&mutex1);
  //take inputs
  printf("Enter values of matrix a: \n");
  for(int i=0; i<2; i++){
    for(int j = 0; j<2; j++){
      printf("Enter a[%d][%d]: ", i, j);
      scanf("%d",&a[i][j]);
    }
  }
  printf("Enter values of matrix b: \n");
  for(int i=0; i<2; i++){
    for(int j = 0; j<2; j++){
      printf("Enter b[%d][%d]: ", i, j);
      scanf("%d",&b[i][j]);
    }
  }
  pthread_mutex_unlock(&mutex1);
}

void *func2(){
  pthread_mutex_lock(&mutex1);
  //take inputs
  int c[2][2];
  for(int i=0; i<2; i++){
    for(int j = 0; j<2; j++){
      c[i][j] = a[i][j] - b[i][j];
    }
  }
  printf("Addition of matrix: \n");
  for(int i=0; i<2; i++){
    for(int j = 0; j<2; j++){
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }
  pthread_mutex_unlock(&mutex1);
}

int main(void){
  pthread_t t1, t2;
  pthread_create(&t1, NULL, &func1, NULL);
  pthread_create(&t2, NULL, &func2, NULL);
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  return 0;
}
