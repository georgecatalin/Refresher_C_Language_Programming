#include <stdio.h>

int some_function(); //prototype of the function


int main(void)
{
    int (* funct_ptr)(); // declaration of the function pointer contains elements of the function prototype

    funct_ptr = some_function; // assign the function pointer

    printf("The address of the function 'some_function' is %p \n",funct_ptr);

    //use the function pointer
    (*funct_ptr)();

    return 0;
}

int some_function()
{
    printf("Print something inside the function...\n");
    return 0;
}