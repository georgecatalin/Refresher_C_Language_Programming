#include <stdio.h>
#include "other.h"

static int year_of_birth;
static int age = 47; //error here

int main(int argc, char *argv[])
{
    printf("The year of birth is %i .\n", year_of_birth); //static global variables are automatically initialized to 0



    return 0;
}