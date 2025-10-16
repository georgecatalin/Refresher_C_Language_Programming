/* ************************************************************************************
A wrapper timer library for POSIX timers abstracts away the low-level details, making timers much easier to use.

 Why Make a Wrapper?

    Hide the complexity of POSIX timer setup (sigevent, itimerspec, etc.)
    Provide easy-to-use functions for creating, starting, stopping, and deleting timers.
    Allow callbacks with user data (using sival_ptr or sival_int).
    Optionally, add error handling, logging, or thread-safe features.
***************************************************************************************/

#include "timer_wrap.h"


void timer_callback_function(union sigval arg)
{
    int *number = (int *) arg.sival_ptr;
    printf("Thread was spawned and the value passed to is \t -> %d.\n", *number);
}

int main(void)
{
    my_timer_t this_timer;
    int my_data = 2011;

    if(timer_create_wrapper(&this_timer,timer_callback_function, &my_data) !=0 )
    {
        perror("Error when creating timer with timer wrapper lib");
        return EXIT_FAILURE;
    }

    if(timer_start_wrapper(&this_timer,5,2) != 0)
    {
        perror("Error when arming timer");
        return EXIT_FAILURE;
    }

    printf("SIGEV_THREAD timer running. Waiting for 10 seconds...\n");
    sleep(10);

    timer_delete_wrapper(&this_timer);

    return 0;
}