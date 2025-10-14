#include <stdio.h>

/*
An inline function is a function for which a compiler is advised to substitute the function's body for each call to the function
,directly at the point of the call. 

This can be a useful optimization technique to reduce the overhead associated with a function call, such as saving registers 
and pushing/popping arguments on the stack.


How It Works
-------------
When you declare a function with the inline keyword, you are giving a hint to the compiler. 
The compiler may choose to inline the function, meaning it will replace the function call with the actual code from the 
function's body.


This is a trade-off:

    Performance: 
    By eliminating the function call overhead, inline functions can result in faster execution, especially for small, 
    frequently called functions.

    Code Size: 
    Replacing each function call with the function's code can increase the overall size of the compiled executable, 
    which can lead to other performance penalties if the code is too large.


The inline keyword is a suggestion, not a command. The compiler makes the final decision on whether to inline a 
function based on its own heuristics,

*/


inline int add(int number1, int number2);

int main(void)
{
    int g = 46;
    int m = 14;

    int sum = add(g,m); //at the moment of calling this function compiler is advised as per C99 standard to replace with the body of the function

    printf("The sum of the numbers is %d + %d = %d \n", g, m, sum);


    return 0;
}


int add(int number1, int number2)
{
  return number1 + number2;
}