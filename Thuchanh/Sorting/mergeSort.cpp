#include <iostream>
#include <random>
using namespace std;

template <class T>
void merge(T arr[], int l, int m, int r);
template <class T>
void mergeSort(T arr[], int l, int r);
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
    mergeSort(arr, 0, n-1);

    printArr(arr,n);

    return 0;
}

template <class T>
void merge(T arr[], int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;

    T* arrLeft = new T[n1];
    T* arrRight = new T[n2];

    for (int i = 0; i < n1; i++) {
        arrLeft[i] = arr[l+i];
    }
    for (int i = 0; i < n2; i++) {
        arrRight[i] = arr[m+i+1];
    }

    int i =0, j =0, k = l;

    while (i < n1 and j < n2) {
        if (arrLeft[i] < arrRight[j]){
            arr[k++] = arrLeft[i++];
        }
        else {
            arr[k++] = arrRight[j++];
        }
    }
    while (i < n1) {
        arr[k++] = arrLeft[i++];
    }
    while (j < n2) {
        arr[k++] = arrRight[j++];
    }
    delete[] arrLeft;
    delete[] arrRight;
}

template <class T>
void mergeSort(T arr[], int l, int r) {
    if (l >= r) return;

    int m = l + (r-l)/2;

    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);

    merge(arr,l,m,r);
}

template <class T>
void printArr(T arr[], int n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}