
#define _POSIX_C_SOURCE 199309L  //this is must-do to enable POSIX Compliant C
#include <signal.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char **argv)
{

    timer_t timer_id;
    struct sigevent sev;
 
    printf("Requesting a new timer for the OS...\n");

    // define the notifier
    memset(&sev, 0, sizeof(struct sigevent));
    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo = SIGRTMIN;  
    //When you create a POSIX timer (using timer_create()), you must tell the system which signal to send when the timer expires.
    //You could use any signal, but it’s safest to use a real-time signal — and SIGRTMIN is the first one available.
    //On Linux: SIGRTMIN = 34 On Linux: SIGRTMAX = 64
    sev.sigev_value.sival_ptr = &timer_id;

    //create the timer
    if(timer_create(CLOCK_REALTIME, &sev, &timer_id) == -1)
    {
       perror("Error to set up timer.");
       exit(EXIT_FAILURE);
    }

    printf("Successfully created a timer.\n");
    printf("The id of the timer is 0x%lx.\n", (long) timer_id);


    //At this point the timer exists, but it is not running. We must use timer_settime() to fire it .
    //We also need a signal handler to catch the signal

    //destroy the timer
    timer_delete(timer_id);
    printf("Timer deleted.\n");


    return 0;
}


