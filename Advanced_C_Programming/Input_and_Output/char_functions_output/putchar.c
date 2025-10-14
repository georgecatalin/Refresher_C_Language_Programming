#include <stdio.h>

// signature: int putchar(int mychar);

int main(void)
{
   int my_char = 0;

   while((my_char=getchar())!=EOF)
   {
      putchar(my_char);
   }

   ungetc(my_char, stdin);

   printf("I completed the execution of the program.\n");

   return 0;
}