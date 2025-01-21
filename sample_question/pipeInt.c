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

  pid=fork();
  if (pid==-1){
    perror("fork");
    exit(1);
  }
  if (pid==0){
    //child process
    wait(NULL);
    printf("From child\n");
    close(fd[1]);
    nbytes= read(fd[0], &read_int, sizeof(int));
    close(fd[0]);
    printf("%d\n", read_int);
    printf("exiting child process\n");
    exit(0);
  }
  else{
    //parent process
    printf("From Parent\n");
    close(fd[0]);
    write(fd[1], &write_int, sizeof(int));	
    close(fd[1]);
    printf("exiting parent process\n");
  }

  return 0;
}

// Basic instructions
/*

to write 
---------

close(fd[0]);
write(fd[1], &write_int, sizeof(int))

to read
--------

close(fd[1])
nbytes=read(fd[0], &read_int, sizeof(int))

*/