#include <stdio.h>

int main(void)
{
   int arr[]={100,200,300};

   void *vptr = &arr[0];//100
   vptr += sizeof(int);

   printf("the next element of the array is %d \n",*(int *)vptr);


    return 0;
}