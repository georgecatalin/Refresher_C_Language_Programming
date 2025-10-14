#include <stdio.h>
#include <signal.h>
#include <unistd.h>

/*
alarm(time_in_seconds) triggers a signal after the amount of time specified
*/

int main(void)
{
    alarm(5);

    for(int i = 0; i<10; ++i)
    {
        printf("%d\n",i);
        sleep(1); //unsigned int sleep(unsigned int seconds);

    return 0;
}