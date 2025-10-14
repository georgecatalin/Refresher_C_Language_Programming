#include <stdio.h>
#include <ctype.h>

/*
signature: int ungets(int ch, FILE * file_pointer);

this function retrieves a character from the file_pointer and returns it to the stdin input stream

*/

int main(void)
{
    char my_character = '\0';

    while (isspace(my_character=getchar())) ;

    printf("the character is %c. \n", my_character);




    return 0;
}