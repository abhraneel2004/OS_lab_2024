#include <stdio.h>      // Standard input/output library
#include <unistd.h>     // Provides access to the POSIX operating system API
#include <sys/types.h>  // Defines data types used in system calls
#include <stdlib.h>     // Provides functions for memory allocation, process control, etc.
#include <string.h>     // Provides string handling functions
#include <sys/wait.h>   // Provides macros related to process termination

int main(void) {
    int fd[2],nbytes; // Array to hold file descriptors for the pipe
    pid_t pid; // Variable to store the process ID
    char st[] = "Hello World\n"; // String to be sent through the pipe
    char readBuffer[80]; // Buffer to read the data from the pipe

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
        write(fd[1], st, strlen(st) + 1); // Write the string to the pipe (including null terminator)
        close(fd[1]); // Close the write end of the pipe after writing
        exit(0); // Exit the child process successfully
    } else { // Parent process
        wait(NULL); // Wait for the child process to finish
        printf("from parent\n"); // Indicate that we are in the parent process
        close(fd[1]); // Close the write end of the pipe in the parent process
        nbytes = read(fd[0], readBuffer, sizeof(readBuffer)); // Read data from the pipe into the buffer
        close(fd[0]); // Close the read end of the pipe after reading
        printf("receiving string: %s\n", readBuffer); // Print the received string

        // Perform character counting on the received string
        int i = 0, alpha = 0, num = 0, sp = 0; // Initialize counters for alphabets, numbers, and special characters
        while (readBuffer[i] != '\0') { // Loop until the end of the string
            char c = readBuffer[i]; // Get the current character
            if (c >= '0' && c <= '9') num++; // Check if the character is a digit
            else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) alpha++; // Check if the character is an alphabet
            else sp++; // If it's neither, count it as a special character
            i++; // Increment the index to check the next character
        }
        // Print the counts of each character type
        printf("No. of integers: %d\n", num);
        printf("No. of alphabets: %d\n", alpha);
        printf("No. of special characters: %d\n", sp); // Print the count of special characters
        exit(0); // Exit the parent process successfully
    }
    return 0; // Return 0 to indicate successful completion of the program
}