/************************************************************
Problem ID: AP0101
Name: Laltu Sardar
Collaborators: NA
Acknowledgements: NA
Time Spent: 30 Mins
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
    int sum_odd, sum_even;
    
    
    for (i=0;i<N;i++){
       fscanf(inp_file_ptr, "%d", &a[i]);   
    }    
    
    fclose(inp_file_ptr);
    
    sum_odd = 0;
    sum_even = 0;
    
    for (i=1;i<=N;i++){
        last_digit =  a[i-1]%10;
        printf("ai %d, last %d\n",  a[i-1], last_digit);
        if (i%2==1){
            sum_odd = sum_odd + last_digit;
            
        }else{
            sum_even = sum_even +last_digit;
        }  
    }    
     
    printf("odd sum = %d  , even sum = %d\n", sum_odd, sum_even); 
    if ((sum_odd-sum_even)%11 ==0){
        printf("yes\n");
    }else{
        printf("no\n");
    }
    

    return 0;
}
