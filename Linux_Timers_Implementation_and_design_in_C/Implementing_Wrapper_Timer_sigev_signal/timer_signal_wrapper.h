#ifndef TIMER_SIGNAL_WRAPPER_H
#define TIMER_SIGNAL_WRAPPER_H

#define _POSIX_C_SOURCE 199309L  //to enable POSIX
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <errno.h>
#include <memory.h>

//declare function pointer for callback function
typedef void (* timer_signal_callback) (int, siginfo_t *, void *);

typedef struct timer_signal
{
    int signumber;
    timer_t timer_id;
    struct sigevent sev;
    struct itimerspec its;
} timer_signal_t;

int timer_signal_create(timer_signal_t *t, timer_signal_callback cb, void *user_data, int signo);
int timer_signal_start(timer_signal_t *t, int first_expiration_sec, int interval_sec);
int timer_signal_stop(timer_signal_t *t);
int timer_signal_delete(timer_signal_t *t);


#endif