#include "Sort.h"

bool ascendingOrder(int a, int b) {
	return a < b;
}
bool descendingOrder(int a, int b) {
	return a > b;
}

void interChangeSort(int* arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j]) {
				swap(arr[i], arr[j]);
			}
		}
	}
}

void selectionSort(int* arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[min] > arr[j])
				min = j;
		}
		swap(arr[i], arr[min]);
	}
}

void insertionSort(int* arr, int n) {
	for (int i = 1; i < n; i++) {
		int temp = arr[i];
		int j = i - 1;;
		while (arr[j] > temp && j >= 0) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}

void bubbleSort(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j > i; j--) {
			if (arr[j] < arr[j - 1])
				swap(arr[j], arr[j - 1]);
		}
	}
}
void quickSort(int* arr, int left, int right) {
	int mid = (left + right) / 2;
	int i = left;
	int j = right;
	do {
		while (arr[i] < arr[mid])
		{
			i++;
		}
		while (arr[j] > arr[mid])
		{
			j--;
		}
		if (i <= j) {
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	} while (i < j);

    if (j > left) quickSort(arr, left, j);
	if (i < right) quickSort(arr, i, right);
}

void merge(int* arr, int left, int mid, int right) {
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int* L = new int[n1];
	int* R = new int[n2];
	int k = left;
	int i = 0, j = 0;
	while (i < n1)
	{
		L[i++] = arr[k++];
	}
	while (j < n2)
	{
		R[j++] = arr[k++];
	}

	i = 0, j = 0;
	k = left;

	while (i < n1 && j < n2)
	{
		if (L[i] < R[j])
			arr[k++] = L[i++];
		else
			arr[k++] = R[j++];
	}
	while (i < n1) {
		arr[k++] = L[i++];
	}
	while (j < n2) {
		arr[k++] = R[j++];
	}
	delete[] L;
	delete[] R;
}

void mergeSort(int* arr, int left, int right) {	
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

void heapify(int* arr, int n, int i, bool (*comparator) (int, int)) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < n && !comparator(arr[left], arr[largest]))
		largest = left;
	if (right < n && !comparator(arr[right], arr[largest]))
		largest = right;
	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest, comparator);
	}
}

void heapSort(int* arr, int n, bool (*comparator) (int, int)) {
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(arr, n, i, comparator);
	}
	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0, comparator);
	}
}