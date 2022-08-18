/************************************************************
Problem ID: AP0106
Name: Laltu Sardar
Collaborators: NA
Acknowledgements: NA
Time Spent: 10 Mins
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
    
    int check=0;
    
    for (i=0;i<N/2;i++){
       if (a[i] != a[N-1-i]){
            check = 1;
            printf("no\n");
            break;
        }
    }    
    if (check==0){ 
        printf("yes\n");
    }

    return 0;
}
