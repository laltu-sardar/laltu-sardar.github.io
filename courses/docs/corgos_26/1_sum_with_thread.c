#include <stdio.h>
#include <pthread.h>


#define SIZE 8
#define THREADS 2

int arr[SIZE] = {1,2,3,4,5,6,7,8};
int partial_sum[THREADS];

void* sum_array(void* arg) {
    int tid = *(int*)arg;
    int start = tid * (SIZE / THREADS);
    int end = start + (SIZE / THREADS);

    partial_sum[tid] = 0;
    

    for(int i = start; i < end; i++) {
        partial_sum[tid] += arr[i];
    }

    pthread_exit(0);
}

int main() {
    pthread_t threads[THREADS];
    int thread_id[THREADS];
    

    for(int i = 0; i < THREADS; i++) {
        thread_id[i] = i;
        pthread_create(&threads[i], NULL, sum_array, &thread_id[i]);
    }

    for(int i = 0; i < THREADS; i++) {
        pthread_join(threads[i], NULL); //The main thread waits until each thread finishes.
    }

    int total = 0;
    for(int i = 0; i < THREADS; i++) {
        total += partial_sum[i];
    }

    printf("Total Sum = %d\n", total);

    return 0;
}
