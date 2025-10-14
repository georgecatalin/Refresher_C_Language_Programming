#include <stdio.h>

int main(int argc, char *argv[])
{
    const float pi = 3.1415f;
    const char mychar[20] = "Hello to C!";

    const int * p_int = NULL; // the value where p_int is poiting to can not be changed
    int const * p_int_1 = NULL;// the value where p_int_1 is poiting to can not be changed

    int * const p_int_2;  // the value of p_int_2 which is the memory address it stores can not be changed


    return 0;
}