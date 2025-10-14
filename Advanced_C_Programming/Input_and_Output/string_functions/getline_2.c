#include <stdio.h>
#include <stdlib.h>

// the version of using a char array , instead of allocating memory on the heap


int main(void)
{
    char my_array[40];
    char *ptr_array = my_array;
    size_t buffer_size=40;
    size_t chars_read;


    chars_read = getline(&ptr_array,&buffer_size,stdin);

    printf("I have read that many characters \t -> %zd. \n", chars_read);
    printf("I have read this string :\n%s",ptr_array);

    return 0;
}