#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int x, int& count) {
    count = 0;
    for (int i = 0; i < n; i++) {
        count++;
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int n, int x, int& count) {
    count = 0;
    int l = 0;
    int r = n - 1;

    while (l <= r) {
        count++;
        int m = (r + l) / 2;
        if (arr[m] == x) {
            return m;
        }
        if (arr[m] < x) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    return -1;
}

int main() {
    int q, n;
    cin >> n >> q;
    
	int* a = new int[n];
	int* b = new int[q];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < q; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < q; i++) {
        int count1, count2;
        int result1 = linearSearch(a, n, b[i], count1);
        int result2 = binarySearch(a, n, b[i], count2);
        cout << "Linear Search: " << result1 << " " << count1 << endl;
        cout << "Binary Search: " << result2 << " " << count2 << endl << endl;
    }
	delete[] a;
	delete[] b;
    return 0;
}
