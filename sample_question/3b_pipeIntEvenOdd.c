#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(void){
  int fd[2], nbytes;
  pid_t pid;
  int read_int, write_int = 11;
  if(pipe(fd)==-1){
    perror("Pipe");
    exit(1);
  }
  pid = fork();
  if (pid == -1){
    perror("fork");
  }
  if (pid==0){
    //child process
    wait(NULL);
    printf("From child\n");
    close(fd[1]);
    nbytes = read(fd[0], &read_int, sizeof(int));
    (read_int%2==0)?printf("Even\n"):printf("Odd\n");
    printf("Exiting child\n");
  }
  else{
    //parent process
    printf("From Parent\n");
    close(fd[0]);
    write(fd[1], &write_int, sizeof(int));
    close(fd[1]);
    printf("Exiting parent\n");
    
  }
  return 0;
}