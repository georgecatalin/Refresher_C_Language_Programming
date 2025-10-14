#include <stdio.h>
#include <string.h>


/*
strdup() and strndup() can be used to duplicate strings.
these two functions are not part of standard C, but they are recognized by the gcc compiler

signatures:
char *strdup(const char *string);
char *strndup(const char *string, size_t number_of_bytes);

*/

int main(void)
{
    char *source = "George Calin";
    char *destination = NULL;

    printf("The destination string before using strdup() function \t -> %s.\n",destination);
    destination = strdup(source);
    printf("The destination string after using strdup() function \t -> %s.\n",destination);

    return 0;
}