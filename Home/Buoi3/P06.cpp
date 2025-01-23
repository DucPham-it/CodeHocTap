#include <iostream>
#include <sstream>

using namespace std;

bool triangle(double a,double b,double c)
{
  
    if ((a+b>c) && (a+c>b) && (b+c>a)) 
         return 1;
    else
         return 0;

}

bool equilateral(double a,double b,double c){
    if ((a==c) && (a==b)) 
         return 1;
    else
         return 0;
}

bool isosceles(double a, double b, double c){
    if ((a==c) || (a==b) || (b==c)) 
         return 1;
    else
         return 0;
}

bool right(double a, double b, double c){
    if ((a*a==c*c+b*b) || (b*b==c*c+a*a) || (c*c==a*a+b*b)) 
         return 1;
    else
         return 0;
}

void testTriangle(double a, double b, double c){
        if (triangle(a,b,c)){
        cout<<"Can form a triangle."<<endl;

        if (equilateral(a,b,c)) {
            cout<<"Equilateral.";       
        }
        else {
            if (isosceles(a,b,c)){
               if (right(a,b,c)){
                    cout<<"Right-isosceles.";
               }
            else{
                cout<<"Isosceles.";
            }
          }
            else{
                if (right(a,b,c)){
                    cout<<"Right.";
                }   
                else{
                    cout<<"Normal.";
                }
            }
        }
    }
    else {
        cout<<"Cannot form a triangle!";
    }
}

int main()
{
    double a,b,c;
    char line[100];

    cout<<"Enter 3 positive real numbers =";
    do {
        cin.getline(line,100);
        if (!(stringstream(line)>>a>>b>>c)){
            cout<<"Wrong! Enter Again:";
        }
    } while (!(stringstream(line)>>a>>b>>c));

    testTriangle(a,b,c);  
    return 0;
}