#include <stdio.h>      // Standard input/output library
#include <unistd.h>     // Provides access to the POSIX operating system API
#include <sys/types.h>  // Defines data types used in system calls
#include <stdlib.h>     // Provides functions for memory allocation, process control, etc.
// #include <string.h>     // Provides string handling functions
#include <sys/wait.h>   // Provides macros related to process termination

int main(void) {
    int fd[2], nbytes; // Array to hold file descriptors for the pipe
    pid_t pid; // Variable to store the process ID
    int read_int;
    int write_int = 101;

    // Create a pipe and check for errors
    if (pipe(fd) == -1) {
        perror("pipe"); // Print error message if pipe creation fails
        exit(1); // Exit the program with an error code
    }

    // Create a new process using fork
    pid = fork();
    if (pid == -1) {
        perror("fork"); // Print error message if fork fails
        exit(1); // Exit the program with an error code
    }

    if (pid == 0) { // Child process
        printf("from child\n"); // Indicate that we are in the child process
        close(fd[0]); // Close the read end of the pipe in the child process

        // Write the integer to the pipe
        write(fd[1], &write_int, sizeof(int));

        close(fd[1]); // Close the write end of the pipe after writing
        exit(0); // Exit the child process successfully
    } else { // Parent process
        wait(NULL); // Wait for the child process to finish
        printf("from parent\n"); // Indicate that we are in the parent process
        close(fd[1]); // Close the write end of the pipe in the parent process

        // Read the integer from the pipe
        nbytes = read(fd[0], &read_int, sizeof(int));

        close(fd[0]); // Close the read end of the pipe after reading
        printf("receiving int: %d\n", read_int); // Print the received integer
    }
    return 0; // Return 0 to indicate successful completion of the program
}