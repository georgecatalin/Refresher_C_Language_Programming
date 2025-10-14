#include <stdio.h>
#include <stdlib.h>

/*
the 'restrict' type qualifier is used also to tell the compiler it can do optimizations to the code when being built
actually  
    int * restrict p_int_a;
    int * restrict p_int_b;

say the during the scope where these two pointer variables have been defined no other pointer will point to the value they point to
namely, no other pointer exists in that scope to point to the value p_int_a points to,
no other pointer exists in that scope to point to the value p_int_b points to

*/

int main(int argc, char *argv[])
{
    int my_array[10];
    int * restrict p_restricted = (int *) malloc(sizeof(int) *10); // no other pointer points to the memory address p_restricted points hence the compiler can do optimizations

    int * p_unrestricted = my_array; // in this case , both my_array and p_unrestricted point to the same address which is 'my_array'

    for(int i=0;i<10;i++)
    {
        p_restricted[i] +=6;
        p_unrestricted[i] +=3;
        my_array[i] *=3;
        p_unrestricted +=5;

        p_restricted[i] +=4;  // since p_restricted is the only one pointing to that value, the compiler can optimize during the build
        //the compiler can do only once p_retricted[i] += (6+4)

       //whereas the same thing can not be done with p_unrestricted[i], cause also my_array[i] performs an operation in between accessing it

    }






    return 0;
}