#include <stdio.h>

int main(void)
{
    register int counter;

    for(counter=0;counter<20; counter++)
    {
        printf("The counter value is %d \n", counter);
    }


    return 0;
}