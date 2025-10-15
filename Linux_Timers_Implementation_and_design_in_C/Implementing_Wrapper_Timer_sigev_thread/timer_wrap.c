#include "timer_wrap.h"

int timer_create_wrapper(my_timer_t *t, timer_callback cb, void *user_data)
{
    memset(t,0,sizeof(my_timer_t));
    t->sev.sigev_notify = SIGEV_THREAD;
    t->sev.sigev_notify_function = cb;
    t->sev.sigev_value.sival_ptr = (void *) user_data;
    t->sev.sigev_notify_attributes = NULL; //use default attributes

    if(timer_create(CLOCK_REALTIME,&t->sev,&t->timer_id) == -1)
    {
        perror("Error when creating timer");
        return EXIT_FAILURE;
    }
    else
    {
        return EXIT_SUCCESS;
    }

}

int timer_start_wrapper(my_timer_t *t, int first_expire, int interval)
{
    t->its.it_value.tv_sec = first_expire;
    t->its.it_value.tv_nsec = 0;

    t->its.it_interval.tv_sec = interval;
    t->its.it_interval.tv_nsec = 0;

    if(timer_settime(t->timer_id,0, &t->its, NULL) == -1)
    {
        perror("Error when arming timer");
        return EXIT_FAILURE;
    }
    else
    {
        return EXIT_SUCCESS;
    }
}

int timer_stop_wrapper(my_timer_t *t)
{
    struct itimerspec itstopped = {0}; // set all the elements of the struct to 0

    if(timer_settime(t->timer_id,0,&itstopped,NULL) == -1)
    {
        perror("Error when stopping");
        return EXIT_FAILURE;
    }
    else
    {
        return EXIT_SUCCESS;
    }
}

int timer_delete_wrapper(my_timer_t *t)
{
    if(timer_delete(t->timer_id) == -1)
    { 
        perror("Error when deleting timer");
        return EXIT_FAILURE;
    }
    else
    {
        return EXIT_SUCCESS;
    }
}