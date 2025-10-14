#include <stdio.h>
#include <stdlib.h>


void foo(int *ptr)  // this function passes a copy of the ptr which points to the same address as ptr
{
   int a = 1978;
   ptr = &a;
}

int main(void)
{
   int *ptr = NULL;
   ptr = (int *) malloc(sizeof(int));

   *ptr = 2011;
   printf("The value where the pointer points to is %d\n", *ptr);

   foo(ptr); //passes a copy of the pointer , not the actual pointer

   printf("The value where the pointer points to is %d\n", *ptr);

   return 0;
}