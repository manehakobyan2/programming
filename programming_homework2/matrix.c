#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

#define MAX 1000

int M = 3, N = 3, P = 3;  // Matrix dimenssions
int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

// Struct for passing row data to threads
typedef struct {
    int row;
} thread_data_t;

// Sequential matrix multiplication
void sequential_matrix_multiplication() {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Thread function to compute a row of matrix C
void* multiply_row(void* arg) {
    thread_data_t* data = (thread_data_t*)arg;
    int row = data->row;
    for (int j = 0; j < P; j++) {
        C[row][j] = 0;
        for (int k = 0; k < N; k++) {
            C[row][j] += A[row][k] * B[k][j];
        }
    }
    return NULL;
}

// Parallel matrix multiplication using threads
void parallel_matrix_multiplication() {
    pthread_t threads[M];
    thread_data_t data[M];

    for (int i = 0; i < M; i++) {
        data[i].row = i;
        pthread_create(&threads[i], NULL, multiply_row, &data[i]);
    }

    // Wait for all thread to finish
    for (int i = 0; i < M; i++) {
        pthread_join(threads[i], NULL);
    }
}

// Function to initialise matrices with random values
void initialize_matrices() {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 10;  // Random values between 0-9
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < P; j++) {
            B[i][j] = rand() % 10;  // Random values between 0-9
        }
    }
}

// Function to print the result matrix
void print_matrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("\nResult Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    initialize_matrices();

    struct timeval start, end;

    // Sequential multiplication
    gettimeofday(&start, NULL);
    sequential_matrix_multiplication();
    gettimeofday(&end, NULL);
    long sec = end.tv_sec - start.tv_sec;
    long usec = end.tv_usec - start.tv_usec;
    printf("Sequential multiplication took %ld.%06ld seconds.\n", sec, usec);
    
    // Print the result of sequential multiplication
    print_matrix(C, M, P);

    // Parallel multiplication
    gettimeofday(&start, NULL);
    parallel_matrix_multiplication();
    gettimeofday(&end, NULL);
    sec = end.tv_sec - start.tv_sec;
    usec = end.tv_usec - start.tv_usec;
    printf("Parallel multiplication took %ld.%06ld seconds.\n", sec, usec);

    // Print the result of parallel multiplication
    print_matrix(C, M, P);

    return 0;
}

