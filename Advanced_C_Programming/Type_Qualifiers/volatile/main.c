#include <stdio.h>

int main(void)
{
    volatile int my_year = 1978;//tells the compiler not to cache the value to the register , but rather load it from memory each time

    volatile int * p_my_year; // do not store the memory location which is the value of 'p_my_year' to the registry, load it


    return 0;
}