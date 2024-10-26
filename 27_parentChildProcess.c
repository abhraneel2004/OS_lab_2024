
// Write a C program that demonstrate the creation of multiple child processes using the fork() system call.
// The program should do the following tasks:
// i) Parent- child relationship:
// - The program should first create a child process from the parent process using fork().
// - It should print a message indicationg the parent process ID and child process ID.

// ii) Child Process behavior:
// - This child process should print a message indicating its own process ID
// - The parent should also print its PID and newly created child process ID.


#include <stdio.h>      // Standard input/output library for printf and perror
#include <stdlib.h>     // Standard library for memory allocation, process control, etc.
#include <unistd.h>     // Provides access to the POSIX operating system API, including fork and getpid
#include <sys/types.h>  // Defines data types used in system calls, such as pid_t

int main() {
    // Create a child process using fork()
    pid_t child_pid = fork(); // fork() creates a new process by duplicating the calling process

    if (child_pid < 0) {
        // Check if fork failed
        perror("Fork failed"); // Print an error message to standard error
        exit(EXIT_FAILURE); // Exit the program with a failure status
    } else if (child_pid == 0) {
        // This block is executed by the child process
        printf("Child Process: My Process ID is %d\n", getpid()); // Print the child's process ID
    } else {
        // This block is executed by the parent process
        printf("Parent Process: My Process ID is %d\n", getpid()); // Print the parent's process ID
        printf("Parent Process: Created Child Process with ID %d\n", child_pid); // Print the child's process ID
    }

    return 0; // Return 0 to indicate successful completion of the program
}