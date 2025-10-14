#include <stdio.h>

/*
there are functions to read a line to a file stream:
1. char *gets(FILE * file_stream); -> it is completely obsolete cause it has got no control agains overflow
2. char *fgets(char *buffer_where_to_store_what_is_read, int number_of_chars_read, FILE * file_stream);

one only uses fgets() when it is certain that the characters read inside the line do not contain the '\0' character.

fgets() reads until it finds out the character '\n' or n-1 characters have been read. the nth character is added automatically '\0'

*/


int main(void)
{
    char my_buffer[100];
    
    fgets(my_buffer,sizeof(my_buffer),stdin);

    printf("I read this :\n%s \n.", my_buffer);

    return 0;
}