#include <iostream>
#include <random>
using namespace std;

template <class T>
void insertionSort(T arr[], int n);
template <class T>
void printArr(T arr[], int n);


int main(){
    int n;
    cin >> n;

    int a[n];

    random_device rd;              
    mt19937 gen(rd());            
    uniform_int_distribution<> dist(1, 10000);

    for (int i = 0; i < n; i++) {
        a[i] = dist(gen);
    }
    insertionSort(a,n);

    printArr(a,n);

    return 0;

}

template <class T>
void insertionSort(T arr[], int n){
    for (int i = 1; i < n; i++){
        int j = i - 1;
        T key = arr[i];
        while (j >= 0 && key < arr[j]) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

template <class T>
void printArr(T arr[], int n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}