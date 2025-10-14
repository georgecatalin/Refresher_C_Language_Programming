#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char mystring[] = "343535 this is the string to be converted";

    char *end = NULL;
    long returnedvalue = 0;

    returnedvalue = strtol(mystring,&end,10);
    
    printf("the long integer number converted from string is %ld \n", returnedvalue);
    printf("The remaining string which could not be converted is %s \n", end);



    return 0;
}