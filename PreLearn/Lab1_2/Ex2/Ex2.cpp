#include <iostream>

using namespace std;

long long fibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    if (n < 0) {
        cout << "Fibonacci is not defined for negative numbers." << endl;
        return 1;
    }

    long long result = fibonacci(n);
    cout << "Fibonacci of " << n << " is " << result << "." << endl;

    return 0;
}

