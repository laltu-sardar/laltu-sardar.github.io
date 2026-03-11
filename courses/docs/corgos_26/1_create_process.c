#include <sys/types.h>	//pid_t
#include <stdio.h>	//printf() and fprintf().
#include <unistd.h>	//fork() execlp()
#include <sys/wait.h>	// wait()

int main()
{
	
    pid_t pid;
    /* fork a child process */
    pid = fork();
    if (pid < 0) { /* error occurred */
        fprintf(stderr, "Fork Failed");
        return 1;
    }
    else if (pid == 0) { /* child process */
        execlp ("/bin/ls","ls",NULL);
        //execlp ("/bin/ls","ls",NULL);
    }
    else { /* parent process */
        /* parent will wait for the child to complete */
        wait(NULL);   
        printf("\nChild Complete\n");
    }
}
