#include <stdio.h>
#include <string.h> //for memcpy

//1. Print Maximum and Minimum Values of unsiged integer
/*
main() {
    unsigned int min, max;
    min = 0;	// 0000 0000 0000 0000 0000 0000 0000 0000 
    printf("unsigned min = %u\n", min);
    max= ~ 0; //bitwise not flips all bits 11111111 11111111 11111111 11111111
    printf("unsigned max = %u\n", max);
}
*/

//1. Print Maximum and Minimum Values of Signed integer
/*
int main() {
     int x = 1;	//0000 0000 0000 0000 0000 0000 0000 0001
    x = x << 31;		//1000 0000 0000 0000 0000 0000 0000 0000
    printf("signed min = %d\n", x);

    int y = ~x;			//01111111 11111111 11111111 11111111
    printf("signed max = %d\n", y);

    return 0;
}
*/
/*1. Print Maximum and Minimum Values of +ve Float
**Maximum +ve normalized float: // 0111 1111 0111 1111 1111 1111 1111 1111 // 0 11111110 11111111111111111111111
**Minimum +ve normalized float: // 0000 0000 1000 0000 0000 0000 0000 0000 // 0 00000001 00000000000000000000000
*/
///*
int main() {
    unsigned int x = 1, y=1, z;	//0000 0000 0000 0000 0000 0000 0000 0001
    //Since bitwise operation only works for integers
    x = x << 31;		//1000 0000 0000 0000 0000 0000 0000 0000
    y = y << 23; 		//0000 0000 1000 0000 0000 0000 0000 0000
    z = x^y;			//1000 0000 1000 0000 0000 0000 0000 0000
    z = ~z;			//0111 1111 0111 1111 1111 1111 1111 1111
    
    float a, b;
    memcpy(&a, &z,4);	//Since memory in y, z are of unsigned int type, we need to use some other types
    printf("Maximum +ve normalized float = %.50e\n", a);
    memcpy(&b, &y,4);
    printf("Minimum +ve normalized float = %.50e\n", b);

    return 0;
}
//*/
