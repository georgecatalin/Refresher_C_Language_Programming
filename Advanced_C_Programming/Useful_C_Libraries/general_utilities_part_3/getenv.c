#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int main(void)
{
    char *mystring = NULL;

    assert((mystring=getenv("HOME")) != NULL);
    printf("the value of HOME environment variable on this system is %s \n", mystring);

    assert((mystring=getenv("PATH")) != NULL);
    printf("the value of PATH environment variable on this system is %s \n", mystring);


    return 0;
}