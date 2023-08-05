/************************************************************
Problem ID: AP0104
Name: Laltu Sardar
Collaborators: NA
Acknowledgements: NA
Time Spent: 10 Mins
************************************************************/

#include<stdio.h>

void main(){
    int marks;
        
    scanf("%d", & marks);
    
    if (marks>=80){
        printf("A+\n");
    }else if(marks>=60){
        printf("A\n");
    }else if(marks>=45){
        printf("B\n");
    }else if(marks>=30){
        printf("C\n");
    }else{
        printf("D\n");
    }
    
    return ;
}
