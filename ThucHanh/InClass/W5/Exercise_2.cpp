#include <iostream>
using namespace std;

struct SortStats {
    int comparisons ;
    int swaps ;
};

void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void threeWayQuickSort(int *arr, int l, int r, int n, SortStats &stats) {
    if (l >= r) {
        return;
    }
    int pivot = arr[l];
    int i = l + 1;
    int lt = l;
    int gt = r;
    while (i <= gt) {
        if (arr[i] < pivot) {
            swap(arr[i], arr[lt]);
            lt++;
            i++;
            stats.swaps++;
        } else if (arr[i] > pivot) {
            swap(arr[i], arr[gt]);
            gt--;
            stats.swaps++;
        } else {
            i++;
        }
        stats.comparisons++;
    }
    cout << "Partition [" << l << ", " << r << "]: ";
    printArray(arr, n);
    threeWayQuickSort(arr, l, lt - 1, n, stats);
    threeWayQuickSort(arr, gt + 1, r, n, stats);

}


int main() 
{
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    printArray(arr,n); 

    SortStats temp;
    temp.comparisons = 0;   
    temp.swaps = 0;
    threeWayQuickSort(arr, 0, n - 1, n, temp);

    cout << "Final array : ";
    printArray(arr, n);
    cout << "Comparisons: " << temp.comparisons << " ";
    cout << "Swaps: " << temp.swaps << endl;


    delete[] arr;
    return 0;
}