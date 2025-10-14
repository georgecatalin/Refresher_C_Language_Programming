#include "other.h"

void function_1(void)
{
    printf("The value is %i.\n", age); //error will be triggered cause static global variables are available only in the file where they are declared
}