#include <stdio.h>

/*

The sprintf() function works just like printf(), but instead of printing formatted text to the console, 
it "prints" it into a string (a character array).

It's used to build formatted strings in memory. 
However, sprintf() is extremely dangerous and should not be used in modern code because it can easily cause buffer overflows.

Signature : int sprintf(char *str, const char *format, ....)

Parameters:

    buffer: A pointer to the character array where the output string will be stored.

    format: The format string with specifiers (%d, %s, etc.).

    ...: The variables to be formatted into the string.

The Big Danger: Buffer Overflows
The critical flaw of sprintf() is that it has no way of knowing the size of the buffer. 
If the formatted text is longer than the buffer can hold, sprintf() will write past the
end of the buffer, corrupting adjacent memory. 

This is a classic buffer overflow, a major source of program crashes and security vulnerabilities.

The sprintf() function returns an int indicating the number of characters written to the buffer.
his count does not include the terminating null character (\0). 
If an encoding error occurs, it returns a negative value.

*/

int main(void)
{
   char my_string[50];
   char language='C';
   int version=11;

   sprintf(my_string,"I am learning %c %d",language,version);
   puts(my_string);


    return 0;
}