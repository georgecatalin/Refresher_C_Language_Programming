#include "timer_signal_wrapper.h"

int timer_signal_create(timer_signal_t *t, timer_signal_callback cb, void *user_data, int signo)
{
    //zerout the pointer
    memset(t,0, sizeof(timer_signal_t));
    t->signumber = signo;

    //set up the signal handler
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO; // This is always set for SIGACTION handling of signals
    sa.sa_sigaction = cb;
    sigemptyset(&sa.sa_mask); // clear the masks if any were previously applied to handle multiple signals at once

    if(sigaction(signo,&sa, NULL) == -1)
    {
        perror("Error when creating sigaction struct");
        return EXIT_FAILURE;
    }

    //create the timer-> populate the handler of the notifier
    t->sev.sigev_notify = SIGEV_SIGNAL;
    t->sev.sigev_signo = signo;
    t->sev.sigev_value.sival_ptr = user_data;
 
    if(timer_create(CLOCK_REALTIME,&t->sev, &t->timer_id) == -1)
    {
        perror("Error when creating timer");
        return EXIT_FAILURE;
    }
    else
    {
        return 0;
    }

}


int timer_signal_start(timer_signal_t *t, int first_expiration_sec, int interval_sec)
{
   t->its.it_value.tv_sec = first_expiration_sec;
   t->its.it_value.tv_nsec = 0;

   t->its.it_interval.tv_sec = interval_sec;
   t->its.it_interval.tv_nsec = 500000000;

   if(timer_settime(t->timer_id,0,&t->its,NULL) == -1)
   {
    perror("Error when arming the timer");
    timer_delete(t->timer_id); //release the resources for the timer
    return EXIT_FAILURE;
   }
   else
   {
    return 0;
   }

}

int timer_signal_stop(timer_signal_t *t)
{
   struct itimerspec its_stop = {0};

   if(timer_settime(t->timer_id,0,&its_stop,NULL) == -1)
   {
    perror("Error when stopping timer");
    return EXIT_FAILURE;
   }
   else
   {
     return 0; 
   }

}


int timer_signal_delete(timer_signal_t *t)
{
   if(timer_delete(t->timer_id) == -1)
   {
    perror("Error when deleting timer");
    return EXIT_FAILURE;
   }
   else
   {
    return 0;
   }
}