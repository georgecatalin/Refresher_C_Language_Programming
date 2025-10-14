#include <stdio.h>
#include <stdlib.h>



/*
signature: int fputs(const char *some_string, FILE * file_pointer);

Note: fputs() does not add automatically the \n character,

***************************************************************************************************
The fputs() function writes a string to a specified file stream. It is a simple and efficient way to write a line of text 
without any formatting.

It is declared in the <stdio.h> header.

Function Breakdown

    Signature: int fputs(const char *str, FILE *stream);

    Parameters:

        str: The null-terminated string you want to write.

        stream: The file stream to write to. This can be a file you've opened (with fopen) or standard streams like stdout (the console) or stderr (standard error).

    Return Value: It returns a non-negative integer on success and EOF on error.

Key Characteristics

    No Automatic Newline: This is the most important feature of fputs(). 
                             Unlike puts(), it does not add a newline character (\n) at the end of the output. 
                            If you want a newline, you must include it in the string itself.

    Writes to Any Stream: It can write to any open file stream, making it more versatile than puts(), 
                            which only writes to stdout.

    No Formatting: It writes the string as-is and cannot format variables like fprintf()

*/

int main(int argc, char *argv[])
{
    FILE *file_pointer = fopen("textfile.txt","w+");
    char *my_string ="Hello from C Programming";

    if(file_pointer==NULL)
    {
        exit(-1);
    }

    fputs(my_string,file_pointer);

    fclose(file_pointer);

    return 0;
}