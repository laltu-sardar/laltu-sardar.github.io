/************************************************************
File Name: ap0005.c 
Problem ID: AP005
Author: Laltu Sardar
Collaborators: NA
Acknowledgements: 
Time Spent: 10 min
************************************************************/
//Problem: To heck whether a given list is a palindrome. 
#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n); // Read the number of elements in the list
    
    int A[n];
    printf("Enter %d integers separated by space: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]); // Read the elements of the list
    }
    
    int isPalindrome = 1; // A flag bit that assumes the list is a palindrome initially
    
    // Check for palindrome using a for loop
    for (int i = 0; i < n / 2; i++) {
        if (A[i] != A[n - 1 - i]) {
            isPalindrome = 0; // If elements don't match, set isPalindrome to false
            break;
        }
    }
    
    // Print the result
    if (isPalindrome) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

    return 0;
}


