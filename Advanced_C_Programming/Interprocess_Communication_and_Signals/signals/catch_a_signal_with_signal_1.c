#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>

/*
when a process receives a signal, it can behave in one of the possibilities:
1. execute the default action as per OS settings SIG_DF
2. ignore the signal SIG_IGN
3. handle/execute the signal

*/


void catch_dividebyzero(int signum);



int main(void)
{
   int v1 = 0, v2 = 0;
   v1 = 1978;
   v2 = 0;

   void (* handle_pointer) (int);

   handle_pointer = signal(SIGFPE,catch_dividebyzero);

   if(handle_pointer == SIG_ERR)  // this is only executed if there is an error when applying the signal() function
   {
    perror("Division by zero");
    exit(EXIT_FAILURE);
   }


   printf("Division %d \n", v1/v2);

    return 0;
}

void catch_dividebyzero(int signum)
{
  if(signum == SIGFPE)
  {
    printf("Received SIGFPE, Divide by zero exception. \n");
    exit(EXIT_SUCCESS);
  }
  else
  {
     printf("Received this signal => %d, Divide by zero exception \n", signum);
     return;
  }

}