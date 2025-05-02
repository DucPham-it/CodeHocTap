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

SortStats shellSort(int *arr, int n) {
    SortStats stats;
    stats.comparisons = 0;
    stats.swaps = 0;
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                stats.comparisons++;
                arr[j] = arr[j - gap];
                stats.swaps++;
            }
            arr[j] = temp;
        }
        cout << "gap = " << gap << " : " <<endl;
        printArray(arr, n);
    }
    return stats;
}



int main() 
{
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    printArray(arr, n); 

    SortStats temp = shellSort(arr, n);
    cout << "Final array : ";
    printArray(arr, n);
    cout << "Comparisons: " << temp.comparisons << " ";
    cout << "Swaps: " << temp.swaps << endl;

    delete[] arr;
    return 0;
}