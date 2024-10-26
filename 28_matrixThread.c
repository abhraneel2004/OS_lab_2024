#include <stdio.h>      // Standard input/output library for printf and scanf
#include <unistd.h>     // Provides access to the POSIX operating system API (not used in this code)
#include <pthread.h>    // Provides support for POSIX threads (pthread)

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // Initialize a mutex for thread synchronization
int a[3][3], b[3][3]; // Declare two 3x3 matrices for input

// Function to input values into matrices A and B
void *func1() {
    pthread_mutex_lock(&mutex); // Lock the mutex to ensure exclusive access to shared resources
    printf("Enter the values for Matrix A:\n");
    // Loop to input values for Matrix A
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Enter A[%d][%d]:", i, j); // Prompt user for input
            scanf("%d", &a[i][j]); // Read value into Matrix A
        }
    }
    printf("Enter the values for Matrix B:\n");
    // Loop to input values for Matrix B
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Enter B[%d][%d]:", i, j); // Prompt user for input
            scanf("%d", &b[i][j]); // Read value into Matrix B
        }
    }
    pthread_mutex_unlock(&mutex); // Unlock the mutex to allow other threads access
    return NULL; // Return NULL to indicate completion
}

// Function to perform addition of matrices A and B
void *func2() {
    pthread_mutex_lock(&mutex); // Lock the mutex to ensure exclusive access to shared resources
    int c[3][3]; // Declare a 3x3 matrix to store the result of the addition
    printf("Addition Operation\n");
    // Loop to add corresponding elements of matrices A and B
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            c[i][j] = a[i][j] + b[i][j]; // Perform the addition
        }
    }
    printf("Resultant matrix:\n");
    // Loop to print the resultant matrix
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%4d", c[i][j]); // Print each element of the resultant matrix
        }
        printf("\n"); // New line after each row
    }
    pthread_mutex_unlock(&mutex); // Unlock the mutex to allow other threads access
    return NULL; // Return NULL to indicate completion
}

int main(void) {
    pthread_t t1, t2; // Declare two thread identifiers
    // Create the first thread to execute func1
    pthread_create(&t1, NULL, &func1, NULL);
    // Create the second thread to execute func2
    pthread_create(&t2, NULL, &func2, NULL);
    // Wait for the first thread to complete
    pthread_join(t1, NULL);
    // Wait for the second thread to complete
    pthread_join(t2, NULL);
    return 0; // Return 0 to indicate successful completion of the program
}