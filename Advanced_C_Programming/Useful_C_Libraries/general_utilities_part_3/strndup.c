#include <stdio.h>
#include <string.h>

int main(void)
{
    char *source = "George Calin";
    char *destination = NULL;

    printf("The destination string before using strdup() function \t -> %s.\n",destination);
    destination = strndup(source,5);
    printf("The destination string after using strdup() function \t -> %s.\n",destination);


    return 0;
}