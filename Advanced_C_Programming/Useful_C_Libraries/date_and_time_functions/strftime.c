#include <stdio.h>
#include <time.h>

int main(void)
{
    time_t current_time;
    time(&current_time);

    struct tm *local_time = localtime(&current_time);
    
    char buffer[30];
    strftime(buffer,sizeof(buffer),"%Y-%m-%d %H-%M-%S", local_time);

    printf("The formatted date is %s.\n",buffer);

    return 0;
}