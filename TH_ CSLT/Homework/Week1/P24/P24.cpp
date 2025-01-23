//24120041-Phạm Võ Đức
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double percent,quota;
    double  max_cashback;
    cin >> percent >> quota;
    
    max_cashback=quota/percent*100; 
	
    cout<< fixed << setprecision(2) << max_cashback;
	return 0;
}
 