#ifndef _P04_H_
#define _P04_H_

struct date
{
    int day,month,year;
};
void inputArray(date a[], int &n);
void printArray(date a[],int n);
bool laterDate(date a, date b);
void arrange(date a[],int n);
#endif