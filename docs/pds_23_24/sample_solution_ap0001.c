/************************************************************
File Name: ap0001.c 
Problem ID: AP001
Author: Laltu Sardar
Collaborators: NA
Acknowledgements: 
Time Spent: 20 min
************************************************************/
//Problem: To determine whether the number that is formed by selecting the last digit of all the $N$ numbers is divisible by $11$.

#include <stdio.h> // This library contains printf(), scanf functions.  

int main() {
    int N;
    printf("Give the number of inputs N: ");
    scanf("%d", &N);  // Read the size of the array N from the user

    
    int A[N];
    printf("Give %d space-separated integers: ", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);  // Read the N space-separated integers and store them in the array A
    }

    int sumOdd = 0;  // Variable to store the sum of digits at odd positions
    int sumEven = 0; // Variable to store the sum of digits at even positions

    // Iterate through the array A to calculate the sums
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            sumOdd += A[i] % 10; // Add the last digit of odd-indexed numbers to sumOdd
        } else {
            sumEven += A[i] % 10; // Add the last digit of even-indexed numbers to sumEven
        }
    }

    // Check if the difference between sumOdd and sumEven is divisible by 11
    if ((sumOdd - sumEven) % 11 == 0) {
        printf("yes\n"); // If divisible by 11, print "yes"
    } else {
        printf("no\n"); // If not divisible by 11, print "no"
    }

    return 0;
}
