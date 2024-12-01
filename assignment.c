#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // initialize random number generator
    srand(time(NULL));
    int minrand = 1;
    int maxrand = 100;

    // WRITE YOUR CODE HERE
    // 1. Check number of arguments
    // arcg is 3 because it includes the program name (argv[0])
    if (argc != 3) {
        printf("Incorrect usage. You provided %d arguments. The correct number of arguments is 2\n", argc - 1);
        return 1; // indicate an error
    }

    // 2. Check if all (two) arguments are integers greater than 0
    // Extract them
    int arg1 = atoi(argv[1]);  // rows
    int arg2 = atoi(argv[2]);  // cols
    // Check 
    if (arg1 <= 0 || arg2 <= 0) {
        printf("Incorrect usage. The parameters you provided are not positive integers");
        return 1;
    }

    // 3. Create matrix
    // Allocate memory for the matrix
    int *matrix = (int *)malloc(arg1 * arg2 * sizeof(int));

    // Initialize the matrix 
    for (int i=0; i < arg1 *arg2; i++) {
        matrix[i] = rand() % (maxrand - minrand + 1) + minrand; // assign random numbers
    }

    // 4. Create file
    FILE *file = fopen("matrix.txt", "w");
    if (file == NULL) {
        printf("Failed to create the file\n");
        // Before exiting, free memory
        free(matrix);
        return 1;
    }

    for (int i=0; i<arg1; i++) {
        for (int j=0; j<arg2; j++) {
            // Write value
            fprintf(file, "%d", matrix[i*arg2 +j]);
            // Except the last column
            if (j<arg2-1) {
                // Add space 
                fprintf(file, " "); 
            }
        }
        // Add new lines
        fprintf(file, "\n");
    }

    fclose(file);

    // Test code for task 3
    // printf("Matrix:\n");
    // for (int i=0; i < arg1; i++) {
    //     for (int j=0; j< arg2; j++) {
    //         printf("%d ", matrix[i*arg2+j]); // Print it as 2D
    //     }
    //     printf("\n");
    // }

    // Free the allocated memory 
    free(matrix);

    return 0;
}
