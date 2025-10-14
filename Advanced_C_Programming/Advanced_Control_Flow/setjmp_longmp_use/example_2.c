#include <stdio.h>
#include <setjmp.h>

jmp_buf my_jump;


void my_function(void)
{
    printf("I am inside my_function().\n");
    longjmp(my_jump, 1978);

    printf("This code will never be executed.");
}


int main(void)
{
    int my_value = setjmp(my_jump);
   

    
    if(my_value)
    {
        printf("I am back in the main() function. \n");
        printf("The value of the control variable  is %i.\n",my_value);
    }
    else
    {
         printf("I am executing this for the first time.\n");
         printf("The value of the control variable  is %i.\n",my_value);
         my_function();
    }

    return 0;
}