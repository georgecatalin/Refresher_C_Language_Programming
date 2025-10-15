#define _POSIX_C_SOURCE 199309L  //to enable POSIX
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

timer_t timer_id;

void timer_handler(int sig, siginfo_t *si, void *uc)
{
    printf("A timer was fired and this signal was sent ->%d\n",sig);
}

int main(void)
{
   struct itimerspec its_new, its_current;
   struct sigevent sev;
   struct sigaction sa;

   //handle the signal
   sa.sa_flags = SA_SIGINFO; // Use sigaction to handle the signal
   sa.sa_sigaction = timer_handler; //execute this function to run when signal is received
   sigemptyset(&sa.sa_mask); //delete all existing masks, thus apply only for this signal
   sigaction(SIGRTMIN,&sa, NULL); //use this sigaction struct to handle the incoming signal, ignore how it was done in the past

   //create the signal
   sev.sigev_notify = SIGEV_SIGNAL; //when timer expires send a signal
   sev.sigev_signo = SIGRTMIN;
   sev.sigev_value.sival_ptr = &timer_id;

   if(timer_create(CLOCK_MONOTONIC,&sev,&timer_id) == -1)
   {
    perror("Error create timer");
    exit(EXIT_FAILURE);
   }

   printf("A timer with the id as 0x%lx was created. \n", (long) timer_id);

   printf("Timer is ready to be set.\n");

   //arm the time
   // set the first expiration of the timer (the first time it fires to 5 seconds)
   its_current.it_value.tv_sec = 5;
   its_current.it_value.tv_nsec = 0;

   //set the subsequent expiration dates at 1.5seconds after the first expiration
   its_current.it_interval.tv_sec = 1;
   its_current.it_interval.tv_nsec = 500000000;

   printf("Setting the first timer at 5 seconds, and after that at every 1.5seconds.\n");
   if(timer_settime(timer_id,0,&its_current, NULL) == -1)
   {
     perror("Error when settime");
     exit(EXIT_FAILURE);
   }

   sleep(1);

   //check when the timer expires the next time
   if(timer_gettime(timer_id,&its_current) == -1)
   {
    perror("Error when getting timer");
    exit(EXIT_FAILURE);
   }

   printf("CHecking the time left until the next expiration of the timer \t -> %ld and %ld.\n",its_current.it_value.tv_sec, its_current.it_value.tv_nsec);

   printf("Waiting for the timer signal now...\n");

   while(1)
   {
    pause();
   }
   

   timer_delete(timer_id);

   return 0;
}