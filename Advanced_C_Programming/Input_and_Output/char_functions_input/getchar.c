#include <stdio.h>

/*
unlike getc(FILE *file_pointer) function, the getchar(void) reads characters only from stdin

signature: int getchar(void);
*/

int main(void)
{
    int my_char = 0; // most of OSs simulate the EOF when entering text at the keyboard by combination of key presses like CTRL+D/Z

    while ((my_char=getchar()) != EOF)
    {
       printf("you entered this character: %c. \n", my_char);
    }
    
    return 0;
}