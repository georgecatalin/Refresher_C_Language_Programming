#define _POSIX_C_SOURCE 199309L  //this is must-do to enable POSIX Compliant C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <memory.h>
#include <errno.h>


void print_current_system_time(void)
{
    time_t current_time;
    time(&current_time);

    printf("Current time is \t ->%s ", ctime(&current_time));

/*
    The `ctime()` function in C converts a time value (of type `time_t`) to a human-readable string representing the local time. It is defined in `<time.h>`. The returned string has the format: `"Wed Jun 30 21:49:08 1993\n"`.

Key points:
- Input: pointer to `time_t` (usually from `time()`).
- Output: pointer to a static string (do not modify or free).
- Not thread-safe (uses static buffer).
- Includes a newline at the end.
    */

}

struct pair
{
    int a;
    int b;
};

typedef struct pair pair_t;

void timer_callback(union sigval arg)
{
    
    print_current_system_time();

    pair_t * pair = (pair_t *) arg.sival_ptr;

    printf("pair is : \t %d and %d \n", pair->a, pair->b);
}

int main(int argc, char **argv)
{
    struct sigevent sev;
    struct itimerspec its;
    timer_t timer_id;

    pair_t my_pair = {1978, 1954};

    //create a sigevent structure to hold the notification as SIGEV_THREAD
    sev.sigev_notify = SIGEV_THREAD;
    sev.sigev_notify_function = timer_callback;
    sev.sigev_value.sival_ptr = &my_pair;
 
    //create a timer
    if(timer_create(CLOCK_REALTIME,&sev, &timer_id) == -1)
    {
        perror("Error when creating timer");
        exit(EXIT_FAILURE);
    }

    //arm(start) the timer
    its.it_value.tv_sec = 5;
    its.it_value.tv_nsec = 0;
    its.it_interval.tv_sec = 2;
    its.it_interval.tv_nsec = 0;

    if(timer_settime(timer_id,0,&its, NULL) == -1)
    {
        perror("Error when arming the timer");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for the timer in the main()...\n");
    pause(); //wait in the main thread until a signal occurs, which is indefinitely

    timer_delete(timer_id);

    return 0;
}