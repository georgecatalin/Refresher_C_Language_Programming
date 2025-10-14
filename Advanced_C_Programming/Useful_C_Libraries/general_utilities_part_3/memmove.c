#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char source[]="abcdefghijklmnoprstuvwz";

    // void *memmove(void *destination, const void *source, size_t number_bytes)
   
    char destination[28];
    printf("The value of the first string is %s.\n",source);

    printf("The value of the second string before memmove() is %s.\n",destination);
    memmove(destination,source, sizeof(char) * strlen(source));
    printf("The value of the second string after memmove() is %s.\n",destination);

    return 0;
}