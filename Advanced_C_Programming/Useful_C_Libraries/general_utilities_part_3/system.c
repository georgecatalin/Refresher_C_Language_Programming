#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char *mystring = "george";

    //changing where a pointer to char points to
    printf("the first string %s \n", mystring);
    mystring = "mara";
    printf("the second string %s \n", mystring);

    char command[50];
    strcpy(command,"ls -lh");
    system(command);

    return 0;
}