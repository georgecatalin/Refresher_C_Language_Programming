#include <stdio.h>

extern void function_1();


int main(int argc, char *argv[])
{
    function_1(); // this function was not included with a .h file ,but can be seen through the 'external' storage class of the function

    return 0;
}