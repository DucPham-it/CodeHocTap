#include "P04.h"
#include <iostream>
using namespace std;

void inputArray(date a[], int &n){ 
      cout<<"Number Of Dates : ";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cout<<"Date (day, month, year) "<<i+1<<" : ";
        cin>>a[i].day>>a[i].month>>a[i].year;     
    }
}

void printArray(date a[], int n){
    cout<<"AFTER ARRANGE"<<endl;
    for (int i=0;i<n;i++){
        cout << "Date (day, month, year) " << i+1 << " : " << a[i].day << " "<< a[i].month << " " << a[i].year <<endl;
    }
}

bool laterDate(date a, date b){
    if (a.year>b.year) return 1;
    if (a.year<b.year) return 0;
    if (a.year==b.year) {
        if (a.month>b.month) return 1;
        if (a.month<b.month) return 0;
        if (a.month==b.month)
            if (a.day>b.day) return 1;
            else return 0; 
    }
}

void arrange(date a[], int n){
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n; j++)
             {
                if (laterDate(a[i],a[j])) {
                    date temp=a[i];
                    a[i]=a[j];
                    a[j]=temp;
                }
             }
    
}
