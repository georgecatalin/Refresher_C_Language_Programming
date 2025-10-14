#include <stdio.h>
#include <stdlib.h>

// signature is : int fgetc(FILE * file_pointer);


int main(void)
{
    FILE * file_pointer =NULL;
    char my_char = '\0';

    file_pointer = fopen("news.txt","r");

    if (!file_pointer)
    {
        printf("Unable to create the file pointer.\n");
        exit(-1);
    }


    printf("reading the file");

    while(1)
    {
        my_char = fgetc(file_pointer);
        printf("%c",my_char);
       
        if(my_char==EOF)
        {
            break;
        }

        
    }

    fclose(file_pointer);
    printf("I closed the file");

    return 0;  
}