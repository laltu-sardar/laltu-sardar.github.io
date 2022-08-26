/************************************************************
Problem ID: AP0101
Name: Laltu Sardar
Collaborators: NA
Acknowledgements: NA
Time Spent: 
************************************************************/

#include<stdio.h>
#include<stdlib.h>

//declaration of functions and passing argument types
int * myMalloc(int );
int if_palindrome(int * , int );


// This functions allocates integer array. It terminates the program if failed
int * myMalloc(int arrLen){ // This is called function definition
   int* arr = (int *)malloc(arrLen* sizeof(int)) ;
   if (arr==NULL){
        printf("Error in  myMalloc: memory allocation failed.\n");
        exit(0); // If memory is not allocated properly then we exit the program
   }
    return arr;
}


//2. Write your main targets as functions.
//This function returns 1 if palindrome, else returns 0
int if_palindrome(int * arr, int arrLen){
    int i, last_digit;
    int sum_odd, sum_even; 
    
    sum_odd = 0;
    sum_even = 0;
    
    for (i=1;i<=arrLen;i++){
        last_digit =  arr[i-1]%10;
        //printf("ai %d, last %d\n",  arr[i-1], last_digit);
        if (i%2==1){
            sum_odd = sum_odd + last_digit;
            
        }else{
            sum_even = sum_even +last_digit;
        }  
    }    
     
    //printf("odd sum = %d  , even sum = %d\n", sum_odd, sum_even); 
    if ((sum_odd-sum_even)%11 ==0){
        printf("yes\n");
        return 1; 
    }else{
        printf("no\n");
        return 0;
    }    
} 


int main(){
    int N, i, no_of_tests, j;
    int *arr;

    FILE *inp_file_ptr;
    inp_file_ptr = fopen("input_AP0101.txt","r"); //1. New FileName
    
  
    ///first scans no_of_tests
    fscanf(inp_file_ptr, "%d", &no_of_tests);
    
    //for each test case we scan N and array
    for (j = 0; j< no_of_tests; j++)
    {
        fscanf(inp_file_ptr, "%d", &N);
        arr =(int *) myMalloc(N*sizeof(int));       //Allocating dynamic memory for the array
        for (i=0;i<N;i++)       //loop to scan array
        {
            fscanf(inp_file_ptr, "%d", &arr[i]);   
        } 
        if_palindrome(arr, N);  // we call the function here after taking inputs
        free(arr);              //Each time it is mandatory to free the used array
    }
       
    fclose(inp_file_ptr);   //closing the test file
   
    return 0;
}
