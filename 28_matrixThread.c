#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int a[3][3], b[3][3];

void *func1(){
  pthread_mutex_lock(&mutex);
  printf("Enter the values for Matrix A:\n");
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      printf("Enter A[%d][%d]:",i,j);
      scanf("%d",&a[i][j]);
    }
  }
  printf("Enter the values for Matrix b:\n");
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      printf("Enter b[%d][%d]:",i,j);
      scanf("%d",&b[i][j]);
    }
  }
  pthread_mutex_unlock(&mutex);
}

void *func2(){
  pthread_mutex_lock(&mutex);
  int c[3][3];
  printf("Addition Operation\n");
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      c[i][j] = a[i][j] + b[i][j];
    }
  }
  printf("Resultant matrix:\n");
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      printf("%4d",c[i][j]);
    }
    printf("\n");
  }
  pthread_mutex_unlock(&mutex);
}

int main(void){
  pthread_t t1,t2;
  pthread_create(&t1,NULL,&func1,NULL);
  pthread_create(&t2,NULL,&func2,NULL);
  pthread_join(t1,NULL);
  pthread_join(t2,NULL);
  return 0;
}