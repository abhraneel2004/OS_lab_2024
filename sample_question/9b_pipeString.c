#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<string.h>

int main(void){
  int fd[2], nbytes;
  pid_t pid;
  char string_ip[]= "Abhra2004\n";
  char readBuffer[30];
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
    close(fd[1]);
    nbytes = read(fd[0], readBuffer, sizeof(readBuffer));
    close(fd[0]);
    printf("%s\n", readBuffer);
    int i = 0;
    while(readBuffer[i]!='\0'){
      printf("%c .. ", readBuffer[i]);
      i++;
    }
    printf("Exiting child\n");
    exit(0);
  }
  else{
    //parent process
    printf("From parent process\n");
    close(fd[0]);
    write(fd[1], string_ip, strlen(string_ip)+1);
    close(fd[1]);
    printf("Exiting parent process\n");
  }
  return 0;
}