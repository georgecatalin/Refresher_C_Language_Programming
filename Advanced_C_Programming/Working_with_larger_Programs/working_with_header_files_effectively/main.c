#include <stdio.h>
#include "other.h"

int main(void)
{
    Date todayDate;
    
    todayDate.Months = February;
    todayDate.Days = Friday;
    todayDate.year = 1990;
    
    changeDate(todayDate);
    isLeapYear(todayDate.year);

    return 0;
}