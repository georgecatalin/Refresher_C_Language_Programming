#include <stdio.h>
#include "other.h"

int year_of_birth = 1978; // this is a global variable which will be referred as external in other files

int main(int argc, char *argv[])
{
    printf("The year_of_birth in 'main.c' is %i \n", year_of_birth);

    function_1();

    printf("The year_of_birth after is was set in 'function_1.c' is %i \n", year_of_birth);


    return 0;
}