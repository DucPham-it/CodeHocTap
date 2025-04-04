#include <iostream>
using namespace std;

void writeArray(int arr[], int n) {
	cout << "[";
	for (int i = 0; i < n-1; i++) {
		cout << arr[i] << " ";
	}
	cout << arr[n - 1];
	cout << "]" << endl;
}
void bubbleSort(int arr[], int n) {
	int comparsions = 0;
	int countSwap = 0;

	cout << "Initial: ";
	writeArray(arr, n);
	for (int i = 0; i < n - 1; i++) {
		for (int j = n-1; j > i; j--) {
			comparsions++;
			if (arr[j] < arr[j - 1]) {
				swap(arr[j], arr[j - 1]);
				countSwap++;
				cout << "Pass " << countSwap << ": ";
				writeArray(arr, n);
			}
		}
	}
	cout << "Final: ";
	writeArray(arr, n);
	cout << "Comparsions: " << comparsions << " Swaps: " << countSwap << endl;
}

void insertionSort(int arr[], int n)
{
	int comparsions = 0;
	int countSwap = 0;
	cout << "Initial: ";
	writeArray(arr, n);
	for (int i = 1; i < n; i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		comparsions++;
		arr[j + 1] = key;
		countSwap++;
		cout << "Insert " << key << ": ";
		writeArray(arr, n);
	}
	cout << "Final: ";
	writeArray(arr, n);
	cout << "Comparsions: " << comparsions << " Swaps: " << countSwap << endl;
}

void quickSort(int arr[], int l, int r)
{
	
	int countSwap = 0;
	if (l < r) {
		int m = (l + r) / 2;
		int pivot = arr[m];
		int i = l;
		int j = r;
		while (arr[i] < pivot) {
			i++;
		}
		while (arr[j] > pivot) {
			j--;
		}
		while (i <= j) {
			
			swap(arr[i], arr[j]);
			i++;
			j--;
			writeArray(arr, r + 1);
		}
		if (l < j) {
			quickSort(arr, l, j);
		}
		else {
			quickSort(arr, i, r);
		}
	}
}	
int main() {
	int n;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cout << "Bubble Sort:" << endl;
	bubbleSort(a, n);
	cout << "Insertion Sort:" << endl;
	insertionSort(a, n);
	cout << "Quick Sort:" << endl;

	quickSort(a, 0, n - 1);
	delete[] a;
	return 0;	
}