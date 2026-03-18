//Only spliting computation
#include <stdio.h>
#include <pthread.h>

#define SIZE 5
#define THREADS 2

int A[SIZE][SIZE] = {
    {1,2,3,4,5},
    {5,4,3,2,1},
    {1,1,1,1,1},
    {2,2,2,2,2},
    {3,3,3,3,3}
};

int B[SIZE][SIZE] = {
    {1,0,0,0,1},
    {0,1,0,1,0},
    {1,0,1,0,1},
    {0,1,0,1,0},
    {1,0,0,0,1}
};

int C[SIZE][SIZE]; // Result matrix

void* multiply(void* arg) {
    int tid = *(int*)arg;

    int rows_per_thread = SIZE / THREADS;
    int start = tid * rows_per_thread;
    int end = (tid == THREADS - 1) ? SIZE : start + rows_per_thread;

    for(int i = start; i < end; i++) {
        for(int j = 0; j < SIZE; j++) {
            C[i][j] = 0;
            for(int k = 0; k < SIZE; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    pthread_exit(0);
}

int main() {
    pthread_t threads[THREADS];
    int thread_id[THREADS];

    // Create threads
    for(int i = 0; i < THREADS; i++) {
        thread_id[i] = i;
        pthread_create(&threads[i], NULL, multiply, &thread_id[i]);
    }

    // Join threads
    for(int i = 0; i < THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print result matrix C
    printf("Result Matrix C:\n");
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            printf("%4d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
