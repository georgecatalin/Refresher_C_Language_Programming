#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   char a[10] = "10";

   int inumber = atoi(a);

   char b[10] ="3.14cf";
   float fnumber = atof(b);

   char c[10] = "100000000";
   long lnumber = atol(c);

   printf("The converted number from string %s is %d .\n", a, inumber);
   printf("The converted number from string %s is %f .\n", b, fnumber);
   printf("The converted number from string %s is %ld .\n", c, lnumber);

    return 0;
}