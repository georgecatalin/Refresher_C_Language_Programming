#include "other.h"
#include <stdio.h>

Date changeDate(Date todaysDate)
{

    //initialize new date with brackets and using the enum
    Date newDate = {March, Saturday, 2024};


    printf("Change date function. The new date is %d/%d/%d\n", newDate.Days, newDate.Months, newDate.year);
    return newDate;
}


bool isLeapYear(int year)
{
    printf("verify if leap year, i am verifying %d .\n", year);
    return true;
}