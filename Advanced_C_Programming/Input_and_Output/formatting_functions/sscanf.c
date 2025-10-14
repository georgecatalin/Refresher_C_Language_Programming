#include <stdio.h>
#include <stdlib.h>

/*
sscanf() is a C library function that reads formatted data from a string, rather than from the keyboard or a file.

The s in sscanf() stands for "string". It works just like scanf() and fscanf(), but its input source is a character string 
that's already in your program's memory.

Signature:
int sscanf(const char *str, const char *format, ...)

Let's break down its parameters:

    const char *str: The source string you want to read data from.

    const char *format: The template string that describes the format of the data to be extracted. 
    It uses format specifiers (e.g., %s, %d) to identify the data.

    ... (ellipsis): The memory addresses (i.e., pointers) of the variables where you want to store the extracted data. 
    You must use the address-of operator &.


*/

int main(void)
{
    char *my_string = " George Calin 46";

    char name[10], surname[10];
    int age;

    int return_value;

    sscanf(my_string,"%s %s %d",surname, name, &age);

    printf("Name = %s \n", name);
    printf("Surname = %s \n", surname);
     printf("Age = %d \n", age);

    return 0;
}