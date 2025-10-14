#include <stdio.h>

/*
there exist two possibilities to pack and work with data at the bit level in C programming language:
1. using bitmasks and bit operations
2. using structures with bit fields

*/

struct packed_data
{
    unsigned int :3; // this will be used for padding the data
    unsigned int f1:1; // this will be used for storing a boolean
    unsigned int f2:1; // this will be used for storing a boolean
    unsigned int f3:1; // this will be used for storing a boolean
    unsigned int type:8; // this will be used for storing an int
    unsigned int index:18; // this wil also be used for storing an int
};



int main(int argc, char *argv[])
{
    struct packed_data my_data;

    //set the information using bit fields of the structure
    my_data.f1 = 1;
    my_data.type = 21;

    //read the information using the bit fields of the structure
    int type_value;
    type_value = my_data.type;

    printf("The value of the type is %i.\n", type_value);


    return 0;
}