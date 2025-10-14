#include <stdio.h>
#include <stdlib.h>

// flexible_array_members has been introduced in C99

struct  my_struct
{
    int array_size;
    int my_array[]; // this is the flexible array member introduced in C99
};

int main(void)
{
    struct my_struct * pmy_struct;
    size_t size;
    
    printf("Enter your desired size for the array:");
    scanf("%zd", &size);

    pmy_struct = malloc(sizeof(struct my_struct) + size * sizeof(int));

    return 0;
}