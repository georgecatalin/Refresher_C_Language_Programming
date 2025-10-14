#include <stdio.h>
#include <time.h>

int main(void)
{
    //get current time
    time_t now = time(NULL);

    struct tm *local_time = localtime(&now);

    printf("year = %d \n", local_time->tm_year +1900);
    printf("month = %d \n", local_time->tm_mon +1);
    printf("day = %d \n", local_time->tm_mday);
    printf("day of week = %d \n", local_time->tm_wday);
    printf("time of day : %02d:%02d:%02d \n", local_time->tm_hour,local_time->tm_min,local_time->tm_sec);

    struct tm *gmt_time = gmtime(&now);
    printf("gmt time of the day:  %02d:%02d:%02d \n ", gmt_time->tm_hour,gmt_time->tm_min,gmt_time->tm_sec);



    return 0;
}