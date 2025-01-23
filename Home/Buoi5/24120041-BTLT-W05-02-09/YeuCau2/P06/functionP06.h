#ifndef _FUNCTION_P06_H_
#define _FUNCTION_P06_H_
#include <string>
using std::string;

struct Student
{
    char Id[9];
    string Name;
    double Literature;
    double Math;  
};
void Input(Student  &Num);
void Output(Student Num);

template <typename... Mark>
double GPA(Mark...mark){
    double total=0;
   double count=sizeof... (mark);
  total=(...+mark);
  if (count>0) return total/count;
  else return 0;
}

string Rank(double GPA);

#endif