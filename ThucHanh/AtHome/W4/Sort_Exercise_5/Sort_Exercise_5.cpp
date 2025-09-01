#include <iostream>
using namespace std;

enum PivotStrategy {
    FIRST_ELEMENT,
    MIDDLE_ELEMENT,
    MEDIAN_OF_THREE
};

void quickSort(int arr[], int n, PivotStrategy strategy);
void quickSort(int arr[], int low, int high, PivotStrategy strategy);
int partition(int arr[], int low, int high, PivotStrategy strategy);

int main() {
    int arr1[] = {10, 7, 8, 9, 1, 5};
    int arr2[] = {10, 7, 8, 9, 1, 5};
    int arr3[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr1) / sizeof(arr1[0]);

    quickSort(arr1, n, FIRST_ELEMENT);
    quickSort(arr2, n, MIDDLE_ELEMENT);
    quickSort(arr3, n, MEDIAN_OF_THREE);

    cout << "Sorted with FIRST_ELEMENT: ";
    for (int i = 0; i < n; i++)
        cout << arr1[i] << " ";
    cout << endl;

    cout << "Sorted with MIDDLE_ELEMENT: ";
    for (int i = 0; i < n; i++)
        cout << arr2[i] << " ";
    cout << endl;

    cout << "Sorted with MEDIAN_OF_THREE: ";
    for (int i = 0; i < n; i++)
        cout << arr3[i] << " ";
    cout << endl;

    return 0;
}

int partition(int arr[], int low, int high, PivotStrategy strategy) {
    int pivotIndex;

    if (strategy == FIRST_ELEMENT) {
        pivotIndex = low;
    } 
    else if (strategy == MIDDLE_ELEMENT) {
        pivotIndex = (low + high) / 2;
    } 
    else { // MEDIAN_OF_THREE
        int mid = (low + high) / 2;
        int a = arr[low], b = arr[mid], c = arr[high];

        if ((a < b && b < c) || (c < b && b < a))
            pivotIndex = mid;
        else if ((b < a && a < c) || (c < a && a < b))
            pivotIndex = low;
        else
            pivotIndex = high;
    }

    int pivot = arr[pivotIndex];  // Lấy giá trị pivot nhưng giữ nguyên vị trí

    int i = low, j = high;
    while (true) {
        while (arr[i] < pivot) i++;  // Tìm phần tử >= pivot bên trái
        while (arr[j] > pivot) j--;  // Tìm phần tử <= pivot bên phải
        if (i >= j) break;  // Nếu hai con trỏ gặp nhau, dừng lại
        swap(arr[i], arr[j]);  // Hoán đổi hai phần tử không đúng chỗ
        i++;
        j--;
    }

    return pivotIndex;  // Trả về vị trí pivot ban đầu
}

void quickSort(int arr[], int low, int high, PivotStrategy strategy) {
    if (low < high) {
        int pi = partition(arr, low, high, strategy);
        quickSort(arr, low, pi - 1, strategy);
        quickSort(arr, pi + 1, high, strategy);
    }
}

void quickSort(int arr[], int n, PivotStrategy strategy) {
    quickSort(arr, 0, n - 1, strategy);
}
