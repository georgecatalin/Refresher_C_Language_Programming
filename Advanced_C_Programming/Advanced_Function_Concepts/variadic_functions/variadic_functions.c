#include <stdio.h>
#include <stdarg.h> //this contains the MACROS that allow working with variable number of arguments functions (variadic)

/*
Variadic functions are functions that can accept a variable number of arguments. 
They are a powerful feature in C, used for functions like printf and scanf, where the number and types of arguments are 
not fixed at compile time.

How They Work
-------------
At their core, variadic functions rely on a special mechanism to handle the arguments that follow the initial, fixed parameters. 
The fixed parameters are necessary for the function to access the variable arguments list. 

Declaration: 
You declare a variadic function using an ellipsis (...) at the end of the parameter list. 


For example: int my_sum(int count, ...);. 

The count parameter in this example is a fixed parameter that can be used to indicate the number of variable arguments.



Accessing Arguments:

To access the variable arguments, you use a set of macros defined in the <stdarg.h> header. 

The four main macros are:

    va_list: A type to declare a variable that will hold the arguments.

    va_start: Initializes the va_list variable. It takes the va_list variable and the last fixed parameter's name as arguments.

    va_arg: Retrieves the next argument from the va_list. It takes the va_list variable and the type of the argument to be 
            retrieved.

    va_end: Cleans up the va_list variable. 
            This is important for proper memory management. Otherwise the process will not work well.

*/



double get_average(double var1, double var2, ...); // this is the prototype of a variadic function

int main(int argc, char **argv)
{
   double v1=46.8,v2=13.9;
   int num1=1978, num2=1954;
   long int num3=1954L, num4=1977L;

   printf("The average is %.2f .\n", get_average(v1,30.4,v2,54.1, 0.0));
   printf("The average is %.2f \n", get_average(19.4,45.5,15.4, 0.0));
   printf("The average is %.2f \n", get_average(v1,(double) num1, v2, (double) num2, 0.0));



    return 0;
}

double get_average(double var1, double var2, ...)
{
    va_list parg;

    double sum = var1 + var2;
    double value = 0.0;
    int counter=0.0;

    double average=0.0;

    //initialize the list variable
    va_start(parg,var2);

    //run through the argument list
    while((value = va_arg(parg,double))!=0.0)
    {
        sum += value;
        ++counter;
    }

    va_end(parg);

    average = sum/counter;

    return average;
}

