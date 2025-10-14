#include <stdio.h>

int main(int argc, char *argv[])
{
   int a,b;

   a = 1978, 1954; // this statement is an example of using the , (comma) binary operator
   /*
   it is equivalent with this

        a = 1978;
        1954;
   
   */
    printf("THe value of a is \t %i \n", a);


    int c,d;
    c = 2011;

    d = (c++, printf("\nthe value of c is %i \n", c), c + 100);
    /*
    here the usage of the comma binary operator is equivalent to 

    c++ so c gets 2012 -> the first expression is evaluated with all side effects completed (increment c ) and the result of this expression is discarded
    prints out 2012 on the stdout -> this expression is also evaluated with all side effects completed (it prints out to the screen) and the result of the expression discarded
    d = 2012 +100 = 2112 -> this expression is evaluated the last, and it is assigned to the left side operand.
    
    */

    printf("The value of d is %i \n",d); //2112

    return 0;
}