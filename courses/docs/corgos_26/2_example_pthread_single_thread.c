/* Source: Operating System Concepts by Avi Silberschatz, Peter B. Galvin, and Greg Gagne.  Global Edition. Wiley, 2023. ISBN: 9781119320913. */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum; /* this data is shared by the thread(s) */
void *runner(void *param); /* thread function */

int main(int argc, char *argv[])
{
    pthread_t tid;          /* thread identifier */
    pthread_attr_t attr;    /* thread attributes */

    /* set default attributes */
    pthread_attr_init(&attr);

    /* create the thread */
    pthread_create(&tid, &attr, runner, argv[1]);

    /* wait for the thread to finish */
    pthread_join(tid, NULL);

    printf("sum = %d\n", sum);
}

/* thread function */
void *runner(void *param)
{
    int i, upper = atoi(param);
    sum = 0;

    for (i = 1; i <= upper; i++)
        sum += i;

    pthread_exit(0);
}

