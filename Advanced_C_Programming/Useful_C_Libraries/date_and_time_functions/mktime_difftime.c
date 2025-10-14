#include <stdio.h>
#include <time.h>

/*
mktime() and difftime() are often used together to calculate the duration between now and a specific future or past date.
    mktime(): Converts a human-readable struct tm (like a specific date you create) into a time_t value (seconds since the Epoch).
    difftime(): Calculates the difference in seconds between two time_t values.

How They Work Together
**********************
A common use case is to figure out how much time is left until a specific event. The workflow is:

    Get the current time as a time_t value.
    Create and populate a struct tm with the details of your target date.
    Use mktime() to convert your target date struct tm into its time_t equivalent.
    Use difftime() to find the difference in seconds between the target time_t and the current time_t.
    Convert the seconds into a more useful unit, like days or hours.

*/

int main(void)
{
    time_t now_time = time(NULL);

    struct tm *target_tm = localtime(&now_time);

    //reset the target_tm to the desired date
    target_tm->tm_year = 2026 - 1900;
    target_tm->tm_mon = 0; //january
    target_tm->tm_mday =1;
    target_tm->tm_hour = 0;
    target_tm->tm_min = 0;
    target_tm->tm_sec = 0;
   
    //convert the target_tm which describes the desired date to epoch time_t
    time_t target_time = mktime(target_tm);
    
    //get the difference between the two dates in epoch time (time_t)
    double difference = difftime(target_time,now_time);

    printf("The difference in seconds between the tow dates is %lf \n", difference);

    printf("The difference in days between the two dates is %lf.\n", difference/86400);


     
    printf("THe initial date is %s.\n", ctime(&now_time));
    printf("THe initial date is %s.\n", ctime(&target_time));

    return 0;
}
