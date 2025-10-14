#include <stdio.h>

void up_and_down(int);


int main(int argc, char **argv)
{

    up_and_down(1);

    return 0;
}

void up_and_down(int number)
{
   
   printf("the number is %d and its memory address is %p \n", number, &number);

   //base condition
   if(number<6)
   {
       //recursive step
   up_and_down(number+1);
   }

 
   printf("the number is %d and its memory address is %p \n", number, &number);
}

/*
It goes "back" to `up_and_down(5)` because of how recursion and the call stack work in C.

When `up_and_down(5)` calls `up_and_down(6)`, the program temporarily leaves `up_and_down(5)` and starts executing `up_and_down(6)`. When `up_and_down(6)` finishes (because it doesn't recurse further), the program returns to where it left off in `up_and_down(5)`—specifically, right after the recursive call.

This is called "unwinding the stack": each function call waits for the next one to finish before it can continue. So after `up_and_down(6)` returns, the code in `up_and_down(5)` after the recursive call runs (the second printf), and then it returns to `up_and_down(4)`, and so on, all the way back to `main`.

This is why you see the "coming down" print statements for each number as the recursion unwinds.
*/