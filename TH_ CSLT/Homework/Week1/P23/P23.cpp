//24120041-Phạm Võ Đức
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double edge,radius,aria,S_circel,S_3threeAngle;
    const double PI=3.14;
	cin >> edge >> radius;

    S_circel=PI*pow(radius,2);
    S_3threeAngle=3*sqrt(3)*pow(edge,2)/4;

    aria=S_circel/2+S_3threeAngle;
        
	
    cout<<fixed<<setprecision(2)<<aria;
	return 0;
}
 