/************************************************************
File Name: ap0004.c 
Problem ID: AP004
Author: Laltu Sardar
Collaborators: NA
Acknowledgements: 
Time Spent: 10 min
************************************************************/
//Problem: To Find the Factorial of a given number.
#include <stdio.h>

int main() {
    int n;
    unsigned long long factorial = 1; // Variable to store the factorial value

    printf("Enter a positive integer: ");
    scanf("%d", &n); // Read the positive integer n from the user

    // Calculate the factorial iteratively
    for (int i = 1; i <= n; i++) {
        factorial *= i; // Multiply the current value of factorial by i
    }

    // Print the calculated factorial
    printf("Factorial of %d = %llu\n", n, factorial);

    return 0;
}


