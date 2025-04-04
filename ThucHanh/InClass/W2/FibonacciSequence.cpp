// 24120041 - Pham Vo Duc

#include <iostream>
using namespace std;

long long fibonaci(int n){
    if ( n == 0) return 0;
    if ( n ==1) return 1;
    return fibonaci(n-1) + fibonaci(n-2);
}

int main(){
    
    int n;
    cout << "Enter N-th number of fibonaci: ";
    cin >> n;

    cout << "Fibonaci number at " << n << " : " << fibonaci(n) << endl;

    return 0;
}