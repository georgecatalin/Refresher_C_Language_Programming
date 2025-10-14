#include <stdio.h>

int main(void)
{
    int my_array[6]={[2]=1978, [5]=1954};

    for(int i=0; i<6; i++)
    {
        printf("the value of element %i in the array is \t %i .\n", i, my_array[i]);
    }



    return 0;
}