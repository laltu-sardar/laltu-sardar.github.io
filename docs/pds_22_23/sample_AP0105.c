/************************************************************
Problem ID: AP0105
Name: Laltu Sardar
Collaborators: NA
Acknowledgements: NA
Time Spent: 5 Mins
************************************************************/

#include<stdio.h>

void main(){
    int n, i, product=1;
     printf("positive integer: ");   
    scanf("%d", & n);
    for(i=1; i<=n; i++){
        product=product*i;
    }
    printf("%d\n", product);
    
    
    
    
    return ;
}
