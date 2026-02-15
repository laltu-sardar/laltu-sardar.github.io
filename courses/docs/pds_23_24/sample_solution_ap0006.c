/************************************************************
File Name: ap0006.c 
Problem ID: AP006
Author: Laltu Sardar
Collaborators: NA
Acknowledgements: 
Time Spent: 10 min
************************************************************/
//Problem: To Compute multiplication $n.2^k$, the division $n/2^k$ and coresponding the remainder.
#include <stdio.h>

int main() {
    int n, k;
    int multiplication, division, remainder;

    // Take user inputs for n and k
    printf("Enter a positive integer n: ");
    scanf("%d", &n);

    printf("Enter a non-negative integer k: ");
    scanf("%d", &k);

    // Compute the multiplication n * 2^k using left shift operator
    multiplication = n << k;

    // Compute the division n / 2^k and find the remainder using right shift operator
    division = n >> k;
    remainder = n - (division << k);

    // Print the results
    printf("Multiplication: %d\n", multiplication);
    printf("Division Quotient: %d\n", division);
    printf("Division Remainder: %d\n", remainder);

    return 0;
}


