#include <stdio.h>

#define LIMIT 8
#define CONDITION

int main(void)
{
   int i = 0;
   int total = 0;


   for ( i = 0; i < LIMIT; i++)
   {
      total += 2*i+1;

      #ifdef CONDITION
        printf("The subtotal is %d.\n", total);
      #endif
   }
   

   printf("Grand Total is %d", total);
   

#define CONST1 47
#define CONST2 14

#if CONST1 == 47 && CONST2 > 10
   puts("hello");
#endif


#define COUNTRY US

#if COUNTRY == US
   #define GREETING "OLA"
#endif


    return 0;
}