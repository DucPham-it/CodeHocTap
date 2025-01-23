//24120041-Phạm Võ Đức
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long  quantity;
    double price, tax;
	cin >> quantity;
    cin >> price;
    
        tax=(price*quantity)*10/100;
	
    cout<<(price*quantity)+tax;
	return 0;
}
