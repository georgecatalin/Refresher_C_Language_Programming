#include <stdio.h>

/*
A union is a special data type in C that allows you to store different data types in the same memory location.

The key thing to understand is that a union can only hold a value for one of its members at a time. Its size is determined by the size of its largest member.

The Key Difference: union vs. struct

This is the best way to understand a union.

    A struct is like a toolbox. 
        It allocates enough memory for all its members, keeping them in separate, distinct compartments. All the tools are in the box at once.

    A union is like a multi-tool handle. 
        It allocates only enough memory for the single largest member. All members share this one space. 
        You can only attach and use one tool head (member) at a time. If you attach the screwdriver bit, you can't use the hammer head.

The critical behavior is that writing to one member will corrupt the values of the others, because they all share the same memory.
*/


union my_union
{
    int a;
    float b;
    char c;
};

int main(int argc, char **argv)
{
    union my_union var_1, var_2, *pvar_1;

    printf("The size of a union is the size if its largest member \t %zd. \n", sizeof(var_1));
    printf("The size of pointer to an union is the size of the pointer for that architecture\t %zd. \n", sizeof(pvar_1)); //8 bytes

    var_1.a = 47;
    printf("The value of var_1.a is %d.\n", var_1.a); //47
    printf("The value of var_1.b is %f.\n", var_1.b); //0.00
    printf("The value of var_1.c is %c.\n", var_1.c); // some garbage

    var_1.c = 'g';
    printf("The value of var_1.a is %d.\n", var_1.a); // some garbage
    printf("The value of var_1.b is %f.\n", var_1.b); //0.00 or some garbage
    printf("The value of var_1.c is %c.\n", var_1.c); // 'g'


    pvar_1 = &var_1;
    pvar_1->b = 3.14;
    printf("The value of pvar_1.a is %d.\n", pvar_1->a); //0 or some garbage
    printf("The value of pvar_1.b is %f.\n", pvar_1->b); // 3.14
    printf("The value of pvar_1.c is %c.\n", pvar_1->c); // some garbage

    return 0;
}