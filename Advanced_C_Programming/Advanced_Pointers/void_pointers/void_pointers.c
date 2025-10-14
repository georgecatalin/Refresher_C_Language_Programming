#include <stdio.h>

int main(void)
{
    void *vptr;

    int a = 1978, *iptr;
    float b = 3.14, *fptr;

   
    vptr = iptr;
    vptr = fptr;

    vptr =  &a;

    printf("Dereferencing the void pointer %d  can be done only with typecasting the void pointer to the appropriate type.\n", *(int *)vptr);


    return 0;
}