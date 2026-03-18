/* Source: Operating System Concepts by Avi Silberschatz, Peter B. Galvin, and Greg Gagne. Global Edition. Wiley, 2023. ISBN: 9781119320913. */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 10

int sum = 0; /* shared data */

void *runner(void *param); /* thread function */

int main(int argc, char *argv[])
{
    pthread_t workers[NUM_THREADS];   /* array of threads */
    pthread_attr_t attr;

    pthread_attr_init(&attr);

    int upper = atoi(argv[1]);

    /* create threads */
    for (int i = 0; i < NUM_THREADS; i++)
        pthread_create(&workers[i], &attr, runner, &upper);

    /* wait for all threads to finish */
    for (int i = 0; i < NUM_THREADS; i++)
        pthread_join(workers[i], NULL);

    printf("sum = %d\n", sum);
}

/* thread function */
void *runner(void *param)
{
    int upper = *(int *)param;

    for (int i = 1; i <= upper; i++)
        sum += i;

    pthread_exit(0);
}

