/************************************************************
File Name: ap0003.c 
Problem ID: AP003
Author: Laltu Sardar
Collaborators: NA
Acknowledgements: 
Time Spent: 10 min
************************************************************/
//Problem: To determine marks depending on the marks
#include <stdio.h>

int main() {
    int marks;
    char grade;
    
    printf("Enter the numerical marks (0-100): ");
    scanf("%d", &marks); // Read the numerical marks
    
    if (marks < 0 || marks > 100) {
        printf("Invalid input. marks must be between 0 and 100.\n");
    } else {
        // Determine the letter marks based on the scale        
        if (marks >= 90) {
            grade = 'A';
        } else if (marks >= 80) {
            grade = 'B';
        } else if (marks >= 70) {
            grade = 'C';
        } else if (marks >= 55) {
            grade = 'D';
        } else {
            grade = 'F';
        }
        
        // Print the grade
        printf("%c\n", grade);
        
    }

    return 0;
}


