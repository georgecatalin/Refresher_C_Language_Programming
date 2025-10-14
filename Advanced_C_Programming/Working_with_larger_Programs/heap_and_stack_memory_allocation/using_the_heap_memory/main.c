#include <stdio.h>
#include <stdlib.h>

double *get_double(double *my_number)
{
    double *temp = (double *) malloc(sizeof(double));

    *temp = *my_number * 2;

    printf("the double of %f is %f.\n", *my_number, * temp);

    printf("*****************************\n");
    printf("The memory address on the heap where temp is pointing to -> %p\n", temp);
    printf("The memory address on the heap where  my_number is pointing to  -> %p\n", my_number);


    return temp;
}


int main(int argc, char *argv[])
{
    double *the_number = (double *) malloc(sizeof(double));
    *the_number = 46.6;

    double *my_double = get_double(the_number);

    free(the_number);
    the_number = NULL;

    free(my_double);
    my_double = NULL;

    return 0;
}