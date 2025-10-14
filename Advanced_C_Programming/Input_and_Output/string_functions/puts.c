#include <stdio.h>
#include <string.h>




/*
The puts() function is a simple way to print a string to the console. 
Its defining feature is that it automatically adds a newline character (\n) at the end of the output.
It's declared in the <stdio.h> header.

Function Breakdown

    Signature: int puts(const char *str);

    Parameter: It takes a single argument: the null-terminated string you want to print.

    Behavior: It writes the string to the standard output (stdout) and then appends a newline character.

 puts() function returns an int.

 On Success 

If the function successfully writes the string to stdout, it returns a non-negative integer. 
The C standard doesn't specify the exact value, only that it won't be negative.

On Failure
If an error occurs (for example, if the standard output stream has been closed or is invalid), 
puts() returns the special constant EOF (End-Of-File).

EOF is a negative integer constant defined in <stdio.h>.

*/


int main(int argc, char *argv[])
{
    char my_string[50];
    strcpy(my_string,"Hello C");

    puts(my_string);


    return 0;
}