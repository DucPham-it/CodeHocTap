// <24120041>
// <PHẠM VÕ ĐỨC>
// <24CTT1>

// Test case 1
// Input:
// Output:
// Test case 2
// Input:
// Output:
// Test case 3
// Input:
// Output:


#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

bool triangle(double a, double b, double c){
	bool test=0;
	if ((a+b>c) && (a+c>b) && (b+c>a)) test=1;
	return test;
}
int main()
{
	double edge1, edge2, edge3,p,s;

	do
	{
		cin>> edge1>> edge2>> edge3;
	} while (((edge1<=0) || (edge1>1000000000)) || ((edge2<=0) || (edge2>1000000000)) || ((edge3<=0) || (edge3>1000000000)) || !(triangle(edge1,edge2,edge3)))  ;
	
	
	
	p=(edge1+edge2+edge3)/2;
	s=sqrt(p*(p-edge1)*(p-edge2)*(p-edge3));
	
	cout<<fixed<<setprecision(2)<<p*2<<" "<<s;
	return 0;
}
