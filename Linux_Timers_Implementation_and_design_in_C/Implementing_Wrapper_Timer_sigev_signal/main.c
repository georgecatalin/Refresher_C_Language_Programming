/* ************************************************************************************
A wrapper timer library for POSIX timers abstracts away the low-level details, making timers much easier to use.

 Why Make a Wrapper?

    Hide the complexity of POSIX timer setup (sigevent, itimerspec, etc.)
    Provide easy-to-use functions for creating, starting, stopping, and deleting timers.
    Allow callbacks with user data (using sival_ptr or sival_int).
    Optionally, add error handling, logging, or thread-safe features.
***************************************************************************************/

#include "timer_signal_wrapper.h"

void signal_function_callback (int signo, siginfo_t *si, void *user_context)
{
   int *number = (int *) si->si_value.sival_ptr;
   printf("[SIGNAL] Timer has expired. This data was transmitted %d with the signal number %d.\n",*number,signo);
}

int main(int argc, char **argv)
{
   int signal_number = SIGRTMIN;
   int my_number = 1954;
   timer_signal_t t;


   timer_signal_create(&t,signal_function_callback,&my_number,signal_number);

   if (timer_signal_start(&t,1,1) != 0)
   {
      perror("Error when arming timer");
      return EXIT_FAILURE;
   }


   printf("The timer will run for 10 seconds...\n");
  
   while(1)
   {
     pause();
   }
  
  
   timer_signal_delete(&t);


    return 0;
}