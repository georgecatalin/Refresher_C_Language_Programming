#include <stdio.h>



int main(int argc, char *argv[])
{
   auto int x = 1978; // x is a local variable for this function -> it boils down to scope, visibility and lifetime (storage class)

   {
     int y = 1989; // y is local to this block of code
   }

    return 0;
}

int function_1(void)
{
    auto double y = 22.4; // y is a local variable to this function_1() 
    return 1978; 
}