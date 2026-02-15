/************************************************************
File Name: ap0007.c 
Problem ID: AP007
Author: Laltu Sardar
Collaborators: NA
Acknowledgements: 
Time Spent: 20 min
************************************************************/
//Problem: To reverses binary representation using bitwise shift operators.
#include <stdio.h>
void printBits(int );
int reverse_bits(int); 

int reverse_bits(int n){
    int reversed = 0;   //storage for the reversed number 
        // Be causius while defining a variable in the middle of a program
    int  nBits = sizeof(int) * 8;
    
    // Reverse the binary representation using bitwise shift operators
    for (int i = 0; i < nBits; i++) {
        reversed |= (n & 1) << (nBits -1 - i);
        n >>= 1;
    }
    return reversed;
} 


void printBits(int n) {
    int nBits; //variable to store number of bits 
    int i;      //variable that counts loop
    int bitValue; //stores the value of a bit 
    
    nBits = sizeof(int) * 8; // Calculate the number of bits in an int (assuming 32-bit)
    // Loop through each bit and print its value
    for (i = nBits - 1; i >= 0; i--) {
        bitValue = (n >> i) & 1;
        printf("%d", bitValue);
    }
    printf("\n");
}

int main() {
    int n;

    // Take user input for n
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input\n");
    } else {
    
        printBits(n); //shows binary presentation before reversing 
        
        int reversed = reverse_bits(n);

        // Print the reversed binary number
        printf("Reversed binary representation: %d\n", reversed);
        printBits(reversed); //shows binary presentation after reversing
    }

    return 0;
}



