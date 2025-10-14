#include <stdio.h>


#define INT_POINTER int *
#define GEORGE int

typedef int * Animal;

int main(void) 
{
    Animal x, y ; // int * x, int * y
  

    INT_POINTER a, b; // by substitution int * a, int b (int because is default)

    GEORGE c; // int c;

    return 0;
}