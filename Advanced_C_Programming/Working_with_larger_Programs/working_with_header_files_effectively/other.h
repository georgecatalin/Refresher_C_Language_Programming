#ifndef OTHER_H
#define OTHER_H

#include <stdbool.h>

enum months 
{
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

enum days
{
    Monday=1,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

struct date
{
    enum months Months;
    enum days Days;
    int year;
};

typedef struct date Date;

Date changeDate(Date todaysDate);
bool isLeapYear(int year);


#endif