#include <stdio.h>
#include <stdlib.h>


/*
signature: ssize_t getline(char **buffer, size_t *size, FILE * file_stream);
        The key difference is that size_t is unsigned and ssize_t is signed. The s at the beginning of ssize_t stands for signed.


**********************************************************************************************

On success, it returns the number of characters read, including the newline character (\n).
On failure or end-of-file, it returns -1.

The key feature of getline() is that it manages the memory for you. 
You provide pointers to a buffer and a size variable, and getline() updates them as needed.

    Signature: ssize_t getline(char **lineptr, size_t *n, FILE *stream);

    Parameters:

        char **lineptr: The address of a char * variable. 
                        getline() will store the address of its dynamically allocated buffer in this pointer.

        size_t *n: The address of a size_t variable. 
                   getline() uses this to track the current size of the buffer, and it will update the value if it needs to  
                   reallocate more memory.

        FILE *stream: The file stream to read from (e.g., stdin for keyboard input or a file handle from fopen()).

    Initialization: Before the first call, you must initialize the pointer to NULL and the size variable to 0. 
    This tells getline() that it needs to allocate a new buffer.

    char *line = NULL;
    size_t len = 0;
*/

int main(void)
{
    size_t buffer_size = 40;
    size_t characters_read = 0;
    char * buffer = NULL;

    buffer = (char *) malloc(buffer_size * sizeof(char)); //allocate memory on the heap to hold the read characters
    
    if(buffer==NULL)
    {
        printf("Memory allocation was not successful");
        exit(-1);
    }

    characters_read = getline(&buffer, &buffer_size, stdin);

    //getline() reads all the characters including the '\n' character, but not the null character

    printf("I have read %zd characters.\n", characters_read);
    printf("I read this string %s\n", buffer);

   //MUST HAVE to safeguard agains memory leaks
    free(buffer);
    buffer=NULL;

    return 0;
}