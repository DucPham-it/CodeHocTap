#include "Sort.h"

int main() {
	int n;
	cin >> n;
	timeRoom* arr = new timeRoom[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i].start >> arr[i].end;
	}
	cout << checkTime(arr, n) << endl;
	cout << findMiniumDay(arr, n) << endl;
	delete[] arr;
	return 0;
}