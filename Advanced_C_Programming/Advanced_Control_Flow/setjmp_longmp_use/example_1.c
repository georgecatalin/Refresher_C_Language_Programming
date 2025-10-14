#include <stdio.h>
#include <stdlib.h>

/*
similarly with the goto statement, the setjmp() and longjmp() functions do branching, but unlike the goto() function, with setjmp() and longjmp() one can jump 
anywhere in the file, even outside the current function (this was a limitation for goto()).

the practical use of setjmp() and longjmp() can be for exceptions handling
*/

#include <setjmp.h>

jmp_buf my_jmp;

int main(void)
{
   int i = setjmp(my_jmp);
   printf("The value of i is %i.\n", i);

   if(i!=0) exit(-1);

   longjmp(my_jmp, 47);
   printf("I am here, at the longjmp() -> this will never be executed");






    return 0;
}