#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
another use case of double pointers is when one wishes to allocate memory to a pointer inside a function and free that memory in the caller function
*/

void foo(char *ptr)
{
    ptr = (char *) malloc(255);
    strcpy(ptr, "Hello from double pointers.");
}


int main(void)
{
    char *ptr=NULL;

    foo(ptr);
    printf("the string is %s. \n", ptr);

    free(ptr); // segmentation fault error here cause it tries to free memory which does not belong to it

    return 0;
}