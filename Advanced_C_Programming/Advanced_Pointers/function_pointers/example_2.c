#include <stdio.h>

void function1(int);
void function2(int);

typedef void FuncType(int);

int main(void)
{
    FuncType *func_ptr = NULL; //declare the function pointer
    func_ptr = function1; //assign the function pointer

    (*func_ptr)(100); // use the function pointer

    func_ptr = function2; //reassign the function pointer
    (*func_ptr)(200); // use the function pointer


    return 0;
}

void function1(int thisarg)
{
    printf("Function1 is using the argument %d\n",thisarg);
}

void function2(int thisarg)
{
    printf("Function2 is using the argument %d\n",thisarg);
}