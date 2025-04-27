#include "Sort.h"

void quickSortTimeStart(timeRoom* arr, int l, int r) {
	int mid = (l + r) / 2;
	int i = l;
	int j = r;
	do
	{
		while (arr[i].start < arr[mid].start)
			i++;
		while (arr[j].start > arr[mid].start)
		{
			j--;
		}
		if (i <= j) {
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	} while (i < j);

	if (i < r) quickSortTimeStart(arr, i, r);
	if (j > l) quickSortTimeStart(arr, l, i);

}

bool checkTime(timeRoom* arr, int n) {
	if (n == 0) return false;
	quickSortTimeStart(arr, 0, n - 1);
	for (int i = 0; i < n - 1; i++) {
		if (arr[i].end >= arr[i + 1].start)
			return false;
	}
	return true;
}

int findMiniumDay(timeRoom* arr, int n) {
	if (n <= 1)  return n;

	quickSortTimeStart(arr, 0, n - 1);

	int count = 1;
	for (int i = 0; i < n - 1; i++) {
		if (arr[i].end >= arr[i + 1].start)
			count++;
	}
	return count;
}
