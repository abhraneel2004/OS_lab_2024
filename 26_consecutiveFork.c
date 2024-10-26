/*
The program should use consecutive fork() system calls to create multiple process.
*/

#include <stdio.h>      // Standard input/output library for printf
#include <unistd.h>     // Provides access to the POSIX operating system API, including fork
#include <sys/types.h>  // Defines data types used in system calls, such as pid_t

int main(void) {
    // Create multiple child processes using fork()
    fork(); // The first fork creates a new process (let's call it Process A)

    fork(); // The second fork is called by both the original process (let's call it Process P) and Process A,
            // resulting in two additional processes (Process B from Process P and Process C from Process A)

    fork(); // The third fork is called by all three processes (P, A, B),
            // resulting in four additional processes (Process D from Process P, Process E from Process A,
            // Process F from Process B, and Process G from Process C)

    // At this point, there are 8 processes in total:
    // 1. Process P (original)
    // 2. Process A (child of P from the first fork)
    // 3. Process B (child of P from the second fork)
    // 4. Process C (child of A from the second fork)
    // 5. Process D (child of P from the third fork)
    // 6. Process E (child of A from the third fork)
    // 7. Process F (child of B from the third fork)
    // 8. Process G (child of C from the third fork)

    printf("Hello World\n"); // Each process prints "Hello World" to the console

    return 0; // Return 0 to indicate successful completion of the program
}