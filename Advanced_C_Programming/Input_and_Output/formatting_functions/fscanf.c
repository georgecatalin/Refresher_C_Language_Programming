#include <stdio.h>
#include <stdlib.h>

/*
fscanf() is a standard C library function used to read formatted data from a file.

Think of the scanf() function, which reads input you type into the console. The f in fscanf() stands for "file"—
it does the same job as scanf(), but instead of reading from the keyboard, it reads from a file you specify. 

Signature: int fscanf(FILE *file_pointer,const char * format, ...)

Let's break it down:

    FILE *stream: A pointer to the FILE object you're reading from. 
    You get this pointer when you open a file in a read mode (e.g., "r") with fopen().

    const char *format: A string that acts as a pattern to match against the text in the file. 
    It contains format specifiers (like %d for an integer, %f for a float, %s for a string) that tell fscanf() 
    what kind of data to expect.

    ... (ellipsis): The memory addresses of the variables where the read data will be stored. 
    You must provide the address using the ampersand & (e.g., &my_variable).

Return Value

The return value of fscanf() is very important for error checking:

    On success, it returns the number of items successfully read and assigned. In the example above, it returns 3 on each successful iteration of the loop.

    On failure or end of file, if no data could be read, it returns EOF (a special constant meaning End Of File). EOF = -1

*/

FILE *file_pointer;
char my_string[100];

int main(void)
{
    if((file_pointer=fopen("test.txt","r"))== NULL)
    {
        exit(-1);
    }

    while (fscanf(file_pointer,"%s",my_string) != EOF)
    {
        printf("%s", my_string);
    }
    
                  
    fclose(file_pointer);

    return 0;
}