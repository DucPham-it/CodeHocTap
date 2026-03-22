#include <iostream>
#include <string>

using namespace std;

long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    if (n < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
        return 1;
    }

    long long result = factorial(n);
    cout << "Factorial of " << n << " is " << result << "." << endl;

    return 0;
}

