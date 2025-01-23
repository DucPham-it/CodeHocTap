#include "functionP08.h"
#include <iostream>
#include <sstream>
using namespace std;

bool leapYear(int year){
    if (year%4==0) return 1;
    else{
        if (year%100==0){
                if (year%400==0) return 1;
                else return 0;
        }
         else return 0; 
    }
}

bool checkInput(date date1){
    if ((date1.day<=0) || (date1.month<=0) || (date1.year<=0)) return 0;
    if (date1.month>12) return 0;
    switch (date1.month)
    {
    case 2:
        if (leapYear(date1.year)){
            if (date1.day>29) return 0;
        }
        else{
            if (date1.day>28) return 0;
        }
        break;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (date1.day>31) return 0;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (date1.day>30) return 0;
        break;
    }
    return 1;
}

void input(date &date1){
    cout<<"Enter date [day, month, year] : ";
    char line[100];
    do{
        cin.getline(line,100);
        if (!(stringstream(line)>>date1.day>>date1.month>>date1.year) || !(checkInput(date1))) cout<<"Wrong! Enter again : ";
    }while(!(stringstream(line)>>date1.day>>date1.month>>date1.year) || !(checkInput(date1)));
}

bool checkLatestDate(date date1,date date2){
    if (date1.year>date2.year){
        return 1;
    }
    else{ 
        if (date1.year<date2.year){
                return 0;
        }
        else{
            if (date1.month>date2.month){
                return 1;
            }
            else{
                if (date1.month<date2.month){
                    return 0;
                }
                else{
                    if (date1.day>date2.day){
                        return 1;
                    }
                    else{
                        return 0;
                    }
                }              
            }
        }
    }
}

date tomorrow(date date1){
    switch (date1.month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
        if (date1.day<31) date1.day=date1.day+1;
        else{
            date1.day=1;
            date1.month=date1.month+1;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (date1.day<30) date1.day=date1.day+1;
        else{
            date1.day=1;
            date1.month=date1.month+1;
        }
        break;
    case 2:
        if (leapYear(date1.year)){
            if (date1.day<29) date1.day=date1.day+1;
            else{
                 date1.day=1;
                 date1.month=date1.month+1;
            }
        }
        else{           
                if (date1.day<28) date1.day=date1.day+1;
                else{
                 date1.day=1;
                 date1.month=date1.month+1;               
                }
        }
        break;
    case 12:
         if (date1.day<31) date1.day=date1.day+1;
        else{
            date1.day=1;
            date1.month=1;
            date1.year+=1;
        }
        break;
    }
    return date1;
}

date yesterday(date date1){
    switch (date1.month)
    {
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (date1.day>1) date1.day=date1.day-1;
        else{
            date1.day=30;
            date1.month=date1.month-1;
        }
        break;
    case 2:
    case 4:
    case 6:
    case 9:
    case 11:
        if (date1.day>1) date1.day=date1.day-1;
        else{
            date1.day=31;
            date1.month=date1.month-1;
        }
        break;
    case 3:     
        if (date1.day>1) date1.day=date1.day+1;
        else{
                date1.month=date1.month-1;
                if (leapYear(date1.year)) date1.day=29;
                else date1.day=28;
            }
        break;
    case 1:
        if (date1.day>1) date1.day=date1.day-1;
        else{
            date1.day=31;
            date1.month=12;
            date1.year-=1;
        }
        break;
    }
    return date1;
}

void output(date date1,date date2){
    if (checkLatestDate(date1,date2))
    {
        cout<<"date 1 is latest than date 2"<<endl;
    }
    else{
        cout<<"date 1 is not latest than date 2"<<endl;
    }
    
    cout<<"Tomorrow of date 1 [day, month, year] : "<<tomorrow(date1).day<<" "<<tomorrow(date1).month<<" "<<tomorrow(date1).year<<endl;
    cout<<"Yesterday of date 2 [day, month, year] : "<<yesterday(date2).day<<" "<<yesterday(date2).month<<" "<<yesterday(date2).year<<endl;
}