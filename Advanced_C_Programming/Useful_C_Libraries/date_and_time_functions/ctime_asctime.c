#include <stdio.h>
#include <time.h>

/*
ctime() and asctime() are simple C functions that convert time values into a standard, pre-formatted string

How They Work

Both functions produce an identical, human-readable string format (Www Mmm dd hh:mm:ss yyyy\n), but they start from different data types:

    ctime(const time_t *timer): 
        This is a convenient one-step function. You give it a pointer to a time_t value (the raw seconds since the Epoch), and it directly returns the formatted local time string. It's equivalent to calling asctime(localtime(timer)).

    asctime(const struct tm *timeptr): 
        This function takes a pointer to a struct tm (the broken-down time structure) and converts it into the standard string format.

*/

int main(void)
{
   time_t current_time; // current_time is the number of seconds since EPOCH that is 1970-01-01 00:00:00
   time(&current_time);
   
   printf("the number of seconds since EPOCH time is %ld: \n",current_time);

   //use ctime() to get a string with the human readable date and time format
   char *ctime_string = ctime(&current_time);
   printf("The date and time string obtained through ctime() \t -> %s \n",ctime_string);


   //use asctime() to get a string with the human readable date and time format
   //first obtain the struct tm *local_time in human readable format data structure

    struct tm *local_time = localtime(&current_time);
    char *asctime_string = asctime(local_time);
    printf("The date and time string obtained through asctime() \t -> %s \n",asctime_string);

    return 0;
}