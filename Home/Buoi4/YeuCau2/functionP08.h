#ifndef _FUNCTION_P08_H_
#define _FUNCTION_P08_H_

struct date
{
    int day,month,year;
};

bool checkInput(date date1);
bool leapYear(int year);
bool checkLatestDate(date date1,date date2);
date tomorrow(date date1);
date yesterday(date date1);
void input(date &date1);
void output(date date1,date date2);

#endif