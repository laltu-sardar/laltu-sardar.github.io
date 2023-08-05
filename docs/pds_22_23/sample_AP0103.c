/************************************************************
Problem ID: AP0103
Name: Laltu Sardar
Collaborators: NA
Acknowledgements: NA
Time Spent: 7 Mins
************************************************************/

#include<stdio.h>

int main(){
    int N;
    int i, last_digit;

    FILE *inp_file_ptr;
    inp_file_ptr = fopen("input.txt","r");

    
    //printf("Give number of input to be taken (N):");
    fscanf(inp_file_ptr, "%d", &N);
    
    int a[N];
    
    
    for (i=0;i<N;i++){
       fscanf(inp_file_ptr, "%d", &a[i]);   
    }    
    
    fclose(inp_file_ptr);
    
    int max,min;    
    max = a[0];
    min = a[0];
    
    
    for (i=1;i<N;i++){
       if (max<a[i]){
            max = a[i];
        }
        if (min>a[i]){
            min = a[i];
        }
    }    
     
    printf("%d %d\n", min, max);

    return 0;
}
