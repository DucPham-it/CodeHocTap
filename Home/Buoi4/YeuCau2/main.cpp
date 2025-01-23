#include "functionP08.h"
#include <iostream>
using namespace std;

int main(){
    date date1, date2;

    cout<<"Date 1:"<<endl;
    input(date1);
    cout<<"Date 2:"<<endl;
    input(date2);
    
    output(date1,date2);
   
    return 0;
}