/*
The program should use consecutive fork() system calls to create multiple process.
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(void){
  fork();
  fork();
  fork();
  printf("Hello World\n");
  return 0;
}