#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double a,b;
	cin >> a >>b;
	cout<<a<<"/"<<b<<"="<<fixed<<setprecision(2)<<a/b;
	return 0;
}
