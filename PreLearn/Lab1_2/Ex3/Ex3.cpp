#include <iostream>
using namespace std;

int sumArray(int arr[], int n) {
    if (n <= 0) return 0;
    return arr[n - 1] + sumArray(arr, n - 1);
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    if (n <= 0) {
        cout << "Array size must be a positive integer." << endl;
        return 1;
    }

    int* arr = new int[n];
    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = sumArray(arr, n);
    cout << "The sum of the array is: " << result << endl;

    delete[] arr;
    return 0;
}
