#include <stdio.h>

#define PI 3.14 //this is a macro with a symbolic constant
#define PRNT(x,y)   printf("The value of x is %d. \n",x);\
                   printf("The value of y is %d.\n", y)


int main(int argc, char **argv)
{
    int age = 46;
    int height = 178;

    //use MACRO
    PRNT(age,height);


    return 0;
}