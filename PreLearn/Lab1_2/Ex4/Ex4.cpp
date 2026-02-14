#include <iostream>

using namespace std;

int binarySearch(int arr[], int left, int right, int target);

int main(int argc, char *argv[]) {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int target;
    cout << "Enter target:";
    cin >> target;
    if (n <= 0) {
        cout << "Array size must be a positive integer." << endl;
        return 1;
    }

    int *arr = new int[n];
    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Index of target is:" << binarySearch(arr, 0, n - 1, target)
         << "\n";

    return 0;
}

int binarySearch(int arr[], int left, int right, int target) {
    if (left > right)
        return -1;

    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
        return mid;

    if (arr[mid] > target) {
        return binarySearch(arr, left, mid - 1, target);
    }

    if (arr[mid] < target) {
        return binarySearch(arr, mid + 1, right, target);
    }

    return -1;
}
