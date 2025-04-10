#include <iostream>
#include <cmath>
using namespace std;

void interChangeSort(int* arr, int n);
void insertionSort(int* arr, int n);
void selectionSort(int* arr, int n);
void bubbleSort(int* arr, int n);
void quickSort(int* arr, int left, int right);
void merge(int* arr, int left, int right);
void mergeSort(int* arr, int left, int right);
void heapify(int* arr, int n);
void heapSort(int *arr, int n);
void shellSort(int* arr, int left, int right);
void countingSort(int* arr, int n);
void radixSort(int* arr, int n);

int main() {
	int n = 10;
	int arr[] = { 5 ,7, 3, 2, 6 , 1, 9 ,8, 4, 10 };
	quickSort(arr, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
	return 0;
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