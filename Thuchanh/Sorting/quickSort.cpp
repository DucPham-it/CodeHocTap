#include <iostream>
#include <random>
using namespace std;


template <class T>
int partition(T* arr, int l, int r);
template <class T>
void quickSort(T* arr, int l, int r);
template <class T>
void printArr(T arr[], int n);

int main() {
    int n;
    cin >> n;

    int arr[n];

    random_device rd;              
    mt19937 gen(rd());            
    uniform_int_distribution<> dist(1, 10000);

    for (int i = 0; i < n; i++) {
        arr[i] = dist(gen);
    }

    quickSort(arr, 0, n-1);

    printArr(arr,n);

    return 0;
}

template <class T>
int partition(T* arr, int l, int r){
    T pivot = arr[r];

    int i = l;

    for (int j = l; j < r; j++){
        if (arr[j] < pivot){
            swap(arr[i], arr[j]);
            i++;
        }
    }

    swap(arr[i], arr[r]);

    return i;
}

template <class T>
void quickSort(T* arr, int l, int r){
    if (l >= r) return;
    int pivot  = partition(arr, l, r);

    quickSort(arr, l, pivot-1);
    quickSort(arr, pivot+1, r);
}

template <class T>
void printArr(T arr[], int n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}
