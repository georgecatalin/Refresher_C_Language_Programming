#include <stdio.h>
#include "file1.h"
#include "file2.h"

int my_var = 2011; // this is a global variable which will be handled as external in other files

int main(void)
{
    printf("The value of the variable from the 'main.c' is \t %d . \n", my_var);

    // read the my_var variable via external variables
    printf("The value from the 'file1.c' is \t %d \n.", return_external_var_f1());
    printf("The value from the 'file2.c' is \t %d \n", return_external_var_f2());

    return 0;
}