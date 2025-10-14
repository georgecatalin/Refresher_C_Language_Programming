#include <stdio.h>

// int getc(FILE * file_stream);

int main(void)
{
    char my_char = '\n';

    FILE * file_pointer = NULL;


    if (file_pointer = fopen("news.c","r"))
    {
        my_char = getc(file_pointer);
        printf("%c", my_char);

        while (my_char!=EOF)
        {
            my_char = getc(file_pointer);
            printf("%c", my_char);
        }

        fclose(file_pointer);
    }
    



    return 0;


}