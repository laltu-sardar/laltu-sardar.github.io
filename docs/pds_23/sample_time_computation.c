#include <sys/time.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

// function declarations
void execute_loop_case_1();  
void execute_loop_case_2();
void compute_time(int );

// function definitions

//This function computes sqrt in the loop condition 
void execute_loop_case_1(){ 
    int i, a; 
    float n = 1147483647.1;
    for (i = 0; i< sqrt(n); i++){
        a = i;
    }
    return;
}

//This function computes sqrt before loop condition 
void execute_loop_case_2(){
    int i, a , n = 1147483647;
    float k = sqrt(n);
    for (i = 0; i< k; i++){
        a = i;
    }
    return;
}

// this returns present mechine time in a structure 
struct timeval GetTimeStamp() 
{
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return tv;
}

// This computes time for the above functions, input c is choice for case type
void compute_time(int c){
    struct timeval tv_start= GetTimeStamp(); // Calculate time
    signed long time_in_micros_start = 1000000 * tv_start.tv_sec + tv_start.tv_usec; // Store time in microseconds
    if (c ==1){
        execute_loop_case_1(); // Replace this line with the process that you need to time
    }
    else {
        execute_loop_case_2();
    }
    struct timeval tv_end= GetTimeStamp(); // Calculate time
    signed long time_in_micros_end = 1000000 * tv_end.tv_sec + tv_end.tv_usec; // Store time in microseconds
    
    printf("Elapsed time: %ld microsecons\n", (time_in_micros_end - time_in_micros_start ));
}

// The main function
int main()
{
    printf("When the sqrt is in the loop condition\n");
    compute_time(1);
    
    printf("When the sqrt is computed before loop\n");
    compute_time(2);   
    return 0;    
}
