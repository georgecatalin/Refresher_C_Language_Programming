#include <stdio.h>
#include <stdarg.h>

/*
The va_copy() macro is a feature in the C standard library that allows you to make a copy of a va_list object. 

This is essential for situations:
1. where you need to traverse the same list of variadic arguments multiple times within a single function call, or
2. if you need to pass a copy of the argument list to another function.

How It Works and Why It's Needed
--------------------------------

A va_list variable, when initialized with va_start(), points to the first variable argument. 
Each call to va_arg() advances this pointer to the next argument in the list. 


This means that a va_list is a stateful object; once you've iterated through the arguments, you can't go back to the beginning.

Without va_copy(), if you wanted to process the arguments twice, you'd have to call va_start() again, 
but this is undefined behavior according to the C standard. va_copy() solves this problem by creating a fresh, 
independent copy of the va_list at its current state. You can then use the copy to iterate through the remaining arguments 
from that point forward, leaving the original va_list untouched.

*/

double sample_stddev(int count, ...);

int main(int argc, char **argv)
{
    printf("The value is %.f \n.", sample_stddev(4,12.4,35.3,56,4,135.3));
    return 0;
}

double sample_stddev(int count, ...)
{
    double sum_sq_diff = 0;
    double sum = 0;

    va_list args1;
    va_start(args1,count); //start traversing the variable list of arguments

    va_list args2;
    va_copy(args2, args1);  //copy the arguments list cause it will be needed to be traversed twice

    //run through the list of parameters
    for (size_t i = 0; i < count; i++)
    {
        double my_number = va_arg(args1,double);
        sum += my_number;
    }
    
    va_end(args1);
    double mean = sum/count;

    printf("The mean is %f, \n", mean);
 
    //run through the list of parameters in the second list of parameters
    for (size_t i = 0; i < count; i++)
    {
        double my_number = va_arg(args2,double);
        sum_sq_diff = (my_number - mean) * (my_number - mean);
    }
    
    va_end(args2);

    printf("The sum_sq_diff is %f \n", sum_sq_diff);

    return sum_sq_diff/count;
}