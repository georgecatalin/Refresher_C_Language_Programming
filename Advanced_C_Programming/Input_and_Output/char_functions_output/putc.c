#include <stdio.h>

int main(void)
{
    char my_char = '\0';
    FILE * file_pointer = NULL;
    FILE * file_pointer_1 = NULL;

    if (file_pointer=fopen("news.txt","r"))
    {
        file_pointer_1=fopen("newfile.txt","w");

        my_char = getc(file_pointer);

        while(my_char!=EOF)
        {
            putc(my_char,file_pointer_1);
            my_char = getc(file_pointer);
        }

    fclose(file_pointer);       
    }
    return 0;
}