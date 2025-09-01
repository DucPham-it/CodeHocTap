#include <iostream>
using namespace std;

int countAu = 0;
int MaxAu = 0;
int ntemp;

void printArray(int* arr, int n)
{
    for (int i = 0; i< n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int *arr, int l, int m, int r) 
{
    int m2 = m +1;

    if (arr[m] <= arr[m2]) return;

    while (l <= m && m2 <= r) {
        if (arr[l] <= arr[m2]){
            l++;
        }
        else{
            int key = arr[m2];
            int i;
            for (i = m2; i > l; i--){
                arr[i] = arr[i-1];
            }
            arr[l] = key;
            l++;
            m++;
            m2++;        
        }
    }
}

void mergeSort(int* arr, int l, int r)
{
    if (l < r){
        countAu++;
        MaxAu = max(MaxAu, countAu);
        int m = l + (r - l)/2;
        mergeSort(arr,l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
        printArray(arr, ntemp);
        countAu--;
    }
}


int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    ntemp = n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    mergeSort(arr,0,n-1);

    printArray(arr,n);
    cout << "Max au :" << MaxAu << endl;
    delete[] arr;
    return 0;
}

