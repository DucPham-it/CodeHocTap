//24120041-Phạm Võ Đức
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double km, hour, minute, second;
    double minute_Changed, hour_Changed, pace, speed;
    cin >> km >> hour >> minute >> second;
   
        minute_Changed=hour*60+minute+second/60;
        hour_Changed=hour+minute/60+second/3600;

        pace=minute_Changed/km;
        speed=km/hour_Changed;

    cout<< fixed << setprecision(2) << speed << setw(5) << pace;
	return 0;
}
 