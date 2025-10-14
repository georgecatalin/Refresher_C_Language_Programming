#include "double_pointers.h"

int main(void)
{
    int a = 46;

    int *p1 = NULL;
    int **p2 = NULL;

    p1 = &a;
    p2 = &p1;

    printf("The address of the variable a is %p.\n", &a);
    printf("The address of the variable p1 is %p.\n", &p1);
    printf("The address of the variable p2 is %p.\n", &p2);

    printf("The value stored at a is %d.\n", a);
    printf("The value stored at p1 is %p.\n", p1);
    printf("The value stored at p1 is %p.\n", p2);

    printf("The value p1 is pointing to is %d.\n", *p1); //46
    printf("The value p2 is pointing to is %p.\n", *p2); // value stored at p1
    printf("The value p1 is double pointing to is %d.\n", **p2); //46

    return 0;
}