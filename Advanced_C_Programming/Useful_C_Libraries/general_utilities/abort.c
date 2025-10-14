#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    FILE * fp;

    fp = fopen("thisfile.doc","r");

    if(!fp)
    {
        printf("Unable to open file");
        abort();
    }

    printf("File opened well");
    fclose(fp);


    return 0;
}