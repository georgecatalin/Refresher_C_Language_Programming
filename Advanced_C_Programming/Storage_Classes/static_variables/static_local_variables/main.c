#include <stdio.h>

void function_1(void)
{
    static int my_var = 1980;
    int auto_var = 2011;

    printf("The value of the static variable is %d and of the auto variable is %d.\n", my_var, auto_var);

    my_var ++;
    auto_var ++;

}

int main(int argc, char *argv[])
{
    for(int i = 0; i<10; i++)
    {
        function_1();

    }

    return 0;
}