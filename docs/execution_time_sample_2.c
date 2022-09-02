/************************************************************
File Name: execution_time_sample_1.c //
Problem: Finding execution time of a factorial function in seconds. 
Name:
Collaborators:
Acknowledgements:
Time Spent:
************************************************************/

#include <stdio.h>
//#include <time.h>       // for clock(), CLOCKS_PER_SEC, clock_t
#include <sys/time.h>     // for timeval, tv_sec, tv_usec

#define MAX_FACT 20 

long int factorial_I(int );
long int factorial_R(int );

long int factorial_I(int n){ //factorial Iterative
    int i;
    long int fact=1;
    
    for(i=1;i<=n;i++)
    {
        fact=fact*i;
    }
    return fact;
}

long int factorial_R(int n){ //factorial Recursive 
    if (n>=1)
        return n*factorial_R(n-1);
    else
        return 1;
}

 
// main function to find the execution time of a C program
int main()
{
    long int fact; // to store the factorial value
    //double time_spent = 0.0;    //We will use this variable, to store exucution time 
    //clock_t time_start, time_end ;  // clock_t is a structure defined in time.h that stores clock time
    unsigned long time_spent = 0;
    struct timeval time_start, time_end;

    int n =-1;      //to compute n!
    while((n<0)||(n>MAX_FACT)){
        printf("Provide an positive integer n <= %d: ", MAX_FACT);
        scanf("%d", &n);
    }
        
    
    //For iterative method 
    //time_start = clock();
    gettimeofday(&time_start, NULL);
    fact  = factorial_I(n);
    //time_end = clock();    
    gettimeofday(&time_end, NULL);
    //time_spent = (double)(time_end - time_start) / CLOCKS_PER_SEC; // dividing the difference by CLOCKS_PER_SEC to convert to seconds
    time_spent =  (time_end.tv_sec - time_start.tv_sec) * 1000000 + time_end.tv_usec - time_start.tv_usec ; // calculate time in microsecond
    printf("The time taken to calculate %d!= %ld in Iterative method %lu microseconds\n", n, fact, time_spent);

    //For Recursive method 
    gettimeofday(&time_start, NULL);
    fact  = factorial_R(n);
    gettimeofday(&time_end, NULL);
    time_spent =  (time_end.tv_sec - time_start.tv_sec) * 1000000 + time_end.tv_usec - time_start.tv_usec ; // calculate time in microsecond
    printf("The time taken to calculate %d!= %ld in Recursive method %lu seconds\n", n, fact, time_spent);

 
    return 0;
}
