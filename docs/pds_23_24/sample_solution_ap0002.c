/************************************************************
File Name: ap0002.c 
Problem ID: AP002
Author: Laltu Sardar
Collaborators: NA
Acknowledgements: 
Time Spent: 15 min
************************************************************/
//Problem: To determine max/min of N given integers

#include <stdio.h> // This library contains printf(), scanf functions.  
#include <limits.h> // For INT_MAX and INT_MIN constants

int main() {
    int N;
    printf("Give the number of inputs N: ");
    scanf("%d", &N);  // Read the number of input integers N

    int max = INT_MIN;  // Initialize max to the smallest possible integer
    int min = INT_MAX;  // Initialize min to the largest possible integer

   
    printf("Give %d space-separated integers: ", N);
    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);  // Read the N space-separated integers and store them in the array A
    }
     // Loop to read N integers and update max and min
    for (int i = 0; i < N; i++) {
        if (A[i] > max) { // Update max 
            max = A[i];
        }
        if (A[i] < min) { // Update min
            min = A[i];
        }
    }

    // Print the maximum and minimum values
    printf("max: %d\n", max);
    printf("min: %d\n", min);

    return 0;
}

