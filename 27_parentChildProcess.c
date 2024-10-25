
// Write a C program that demonstrate the creation of multiple child processes using the fork() system call.
// The program should do the following tasks:
// i) Parent- child relationship:
// - The program should first create a child process from the parent process using fork().
// - It should print a message indicationg the parent process ID and child process ID.

// ii) Child Process behavior:
// - This child process should print a message indicating its own process ID
// - The parent should also print its PID and newly created child process ID.


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    // Create a child process
    pid_t child_pid = fork();

    if (child_pid < 0) {
        // Fork failed
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0) {
        // This block is executed by the child process
        printf("Child Process: My Process ID is %d\n", getpid());
    } else {
        // This block is executed by the parent process
        printf("Parent Process: My Process ID is %d\n", getpid());
        printf("Parent Process: Created Child Process with ID %d\n", child_pid);
    }

    return 0;
}