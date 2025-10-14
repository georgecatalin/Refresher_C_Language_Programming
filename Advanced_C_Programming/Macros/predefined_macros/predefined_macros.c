#include <stdio.h>

/*
In C there exist several predefined macros that might be useful when developing C based solutions
*/

void myfunc()
{
    printf("Executing the function %s now.\n",__func__);
}

int main(void)
{
    printf("This file was compiled at %s on %s.\n", __TIME__, __DATE__);
    printf("We are in the file %s and at the line %d.\n", __FILE__,__LINE__);

    myfunc();

    return 0;
}