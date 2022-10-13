#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main () {
   int i, n;
   time_t t;
   
   /* Intializes random number generator */
   srand((unsigned) time(&t)); //should be used only once in a code 

   /* Print 10 random numbers from 0 to 49 */
   for( i = 0 ; i < 10 ; i++ ) {
      printf("%d\n", rand() % 50);
   }
   
   return(0);
}
