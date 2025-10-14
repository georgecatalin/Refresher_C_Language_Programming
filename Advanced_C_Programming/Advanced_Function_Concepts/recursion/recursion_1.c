#include <stdio.h>

/*
Recursion is a programming technique where a function calls itself, either directly or indirectly, to solve a problem. 
It's an elegant and powerful way to handle problems that can be broken down into smaller, self-similar subproblems.

How It Works
----------------

A recursive function needs two key components to work correctly:

1.Base Case: The base case is the condition that stops the recursion. 
    It's the simplest form of the problem that can be solved directly without a further recursive call. 
    Without a base case, the function would call itself infinitely, leading to a stack overflow.

2. Recursive Step: The recursive step is the part of the function that calls itself with a modified input, 
     bringing the problem closer to the base case.

*/


int factorial(int number);

int main(int argc, char **argv)
{
    int n = 19;

    printf("The factorial of %d is \t %d", n, factorial(n));

    return 0;
}

int factorial(int number)
{
    int result = 0;

    //base condition
    if(number==1)
    {
        return 1;
    }
    else //recursive step
    {
        result= number * factorial(number-1);
    }

    return result;
}