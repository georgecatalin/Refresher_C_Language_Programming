#ifndef TIMER_WRAP_H
#define TIMER_WRAP_H

#define _POSIX_C_SOURCE 199309L  //to enable POSIX
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <errno.h>
#include <string.h>

typedef void (* timer_callback) (union sigval);

typedef struct my_timer
{
    timer_t timer_id;
    struct sigevent sev;
    struct itimerspec its;
} my_timer_t;


//create and initialize timer
int timer_create_wrapper(my_timer_t *t, timer_callback cb, void *user_data);

//arm(start) timer
int timer_start_wrapper(my_timer_t *t, int first_expire, int interval);

//stop timer
int timer_stop_wrapper(my_timer_t *t);

//delete timer
int timer_delete_wrapper(my_timer_t *t);

#endif