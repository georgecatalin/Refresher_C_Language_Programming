#include <stdio.h>

/*
fputc() is a function to write characters one by one into a file

signature: int fputs(FILE *file_stream); it returns the character whether not EOF, and EOF if the character is EOF

*/

int main(void)
{
    char my_char = '\0';
    FILE * fp=NULL;


    if(fp=fopen("test.txt","w"))
    {
        for(my_char='A'; my_char<='Z'; my_char++)
        {
            fputc(my_char,fp);
        }

        fclose(fp);

    }

    return 0;
}