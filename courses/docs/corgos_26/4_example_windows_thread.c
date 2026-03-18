/* Source: Operating System Concepts by Avi Silberschatz, Peter B. Galvin, and Greg Gagne.
   Global Edition. Wiley, 2023. ISBN: 9781119320913. */

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

DWORD Sum = 0; /* data shared by the thread */

/* thread function */
DWORD WINAPI Summation(LPVOID Param){
    DWORD Upper = *(DWORD *)Param;
    for (DWORD i = 1; i <= Upper; i++)
        Sum += i;
    return 0;
}

int main(int argc, char *argv[]){
    DWORD ThreadId;
    HANDLE ThreadHandle;
    DWORD Param;

    Param = atoi(argv[1]);

    /* create the thread */
    ThreadHandle = CreateThread(
        NULL,        /* default security attributes */
        0,           /* default stack size */
        Summation,   /* thread function */
        &Param,      /* parameter to thread function */
        0,           /* default creation flags */
        &ThreadId);  /* returns thread identifier */

    /* wait for the thread to finish */
    WaitForSingleObject(ThreadHandle, INFINITE);

    /* close the thread handle */
    CloseHandle(ThreadHandle);

    printf("sum = %lu\n", Sum);
}

