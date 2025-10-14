#define _POSIX_C_SOURCE 200809L
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

/* use sa_sigaction structure instead of sa_handler */

void sigint_handler(int signum, siginfo_t *complete_info, void * context)
{
  printf("I am the function() catching the signal %d which came from the process id %d.\n", signum, complete_info->si_pid);
  exit(EXIT_SUCCESS);   
}

int main(void)
{
    //declare sigaction struct
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));

    //define the members of the struct
    sa.sa_sigaction = sigint_handler;
    sa.sa_flags = SA_SIGINFO; // use this flag to mark the usage of sigaction struct instead of sa_handler
    sigemptyset(&sa.sa_mask); //clears all the signal masks

    if(sigaction(SIGINT,&sa,NULL) == -1)
    {
        perror("Error when catching SIGINT");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        puts("I am running the program until you issue CTRL+C which is SIGINT signal");
        sleep(1);
    }
    

    return 0;
}