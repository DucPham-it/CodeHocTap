#include "functionP06.h"
#include <iostream>
#include <string>
using namespace std;

void Input(Student  &Num){
    cout<<"Enter student profile:"<<endl;

    cout<<"Id: ";
    cin>>Num.Id;

    cout<<"Name: ";
    cin.ignore();
    getline(cin,Num.Name);

    cout<<"Literature: ";
    cin>>Num.Literature;
    
    cout<<"Math: ";
    cin>>Num.Math;
}


string Rank(double GPA){
    if (GPA >= 8.5) return "Excellent";
        else if (GPA >= 7.0) return "Good";
             else if (GPA >= 5.0) return "Fair";
                  else return "Failed";
}

void Output(Student Num){
    double mind=GPA(Num.Literature,Num.Math);
    cout<<"GPA: "<<mind<<endl;
    cout<<"Rank: "<<Rank(mind)<<endl;
}