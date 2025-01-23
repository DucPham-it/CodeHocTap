#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
 
    cout << setw(8) << "*" << endl;
    cout << setw(7) << "*" << setw(2) << "*" << endl;
    cout << setw(6) << "*" << setw(4) << "*" << endl;
    cout << setw(5) << "*" << setw(6) << "*" << endl;
    cout << setw(4) << "*" << setw(8) << "*" << endl;
    cout << setw(3) << "*" << setw(10) << "*" << endl;
    cout << setw(2) << "*" << setw(12) << "*" << endl;
    cout << setfill('*')<<setw(2)<<" "
    << setfill('*')<<setw(2)<<" "
    << setfill('*')<<setw(2)<<" "
    << setfill('*')<<setw(2)<<" "
    << setfill('*')<<setw(2)<<" "
    << setfill('*')<<setw(2)<<" "
    << setfill('*')<<setw(2)<<" "
    << setfill('*')<<setw(2)<<" "<<endl;

double a,b,c,dienTich,p;
    cout<<"Chieu dai canh thu nhat la ";
    cin>>a;
    cout<<"Chieu dai canh thu hai la ";
    cin>>b;
    cout<<"Chieu dai canh thu ba la ";
    cin>>c;
        p=(a+b+c)/2.0;
        dienTich=sqrt(p*(p-a)*(p-b)*(p-c)) ; 
    cout<<"Dien tich tam giac la "<<fixed<<setprecision(2)<<dienTich;
    return 0;
}
