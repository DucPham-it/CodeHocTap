// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠤⠒⠈⠉⠉⠉⠉⠒⠀⠀⠤⣀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⠁⠀⠀⠀⠀⠀⠀⢀⣄⠀⠀⠀⠀⠑⡄⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠰⠿⠿⠿⠣⣶⣿⡏⣶⣿⣿⠷⠶⠆⠀⠀⠘⠀
// ⠀⠀⠀⠀⠀⠀⠠⠴⡅⠀⠀⠠⢶⣿⣿⣷⡄⣀⡀⡀⠀⠀⠀⠀⠀⡇⠀
// ⠀⣰⡶⣦⠀⠀⠀⡰⠀⠀⠸⠟⢸⣿⣿⣷⡆⠢⣉⢀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⢹⣧⣿⣇⠀⠀⡇⠀⢠⣷⣲⣺⣿⣿⣇⠤⣤⣿⣿⠀⢸⠀⣤⣶⠦⠀⠀
// ⠀⠀⠙⢿⣿⣦⡀⢇⠀⠸⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⠀⡜⣾⣿⡃⠇⢀⣤⡀⠀
// ⠀⠀⠀⠀⠙⢿⣿⣮⡆⠀⠙⠿⣿⣿⣾⣿⡿⡿⠋⢀⠞⢀⣿⣿⣿⣿⣿⡟⠁
// ⠀⠀⠀⠀⠀⠀⠛⢿⠇⣶⣤⣄⢀⣰⣷⣶⣿⠁⡰⢃⣴⣿⡿⢋⠏⠉⠁⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠠⢾⣿⣿⣿⣞⠿⣿⣿⢿⢸⣷⣌⠛⠋⠀⠘⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠙⣿⣿⣿⣶⣶⣿⣯⣿⣿⣿⣆⠀⠇
// TRY TO FIX BUG TODAY, BECOME A NICE CODER TOMORROW !!!


//24120041 - Pham Vo Duc

#include <iostream>
#include <chrono>
using namespace std;

int insertionSort(int* arr, int l, int r) {
    int comparisons = 0;
    for (int i = l + 1; i <= r; i++) {
        int x = arr[i];
        int j = i - 1;
        while (j >= l && arr[j] > x) {
            arr[j + 1] = arr[j];
            j--;
            comparisons++;
        }
        arr[j + 1] = x;
        if (j >= l) comparisons++;
    }
    return comparisons;
}

int merge(int arr[], int left, int mid, int right) {
    int comparisons = 0;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int* leftPart = new int[n1];
    int* rightPart = new int[n2];
    
    for (int i = 0; i < n1; i++) leftPart[i] = arr[left + i];
    for (int i = 0; i < n2; i++) rightPart[i] = arr[mid + 1 + i];
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        comparisons++;
        if (leftPart[i] <= rightPart[j]) {
            arr[k++] = leftPart[i++];
        } else {
            arr[k++] = rightPart[j++];
        }
    }
    while (i < n1) arr[k++] = leftPart[i++];
    while (j < n2) arr[k++] = rightPart[j++];
    
    delete[] leftPart;
    delete[] rightPart;
    
    return comparisons;
}

int hybridSort(int arr[], int l, int r, int k) {
    int comparisons = 0;
    if (r - l + 1 <= k) {
        comparisons += insertionSort(arr, l, r);
    } else {
        int m = l + (r - l) / 2;
        comparisons += hybridSort(arr, l, m, k);
        comparisons += hybridSort(arr, m + 1, r, k);
        comparisons += merge(arr, l, m, r);
    }
    return comparisons;
}

template <typename Func , typename ... Args >
double measureExecutionTime ( int& comparrisons, Func func , Args &&... args) {
    auto start = std :: chrono :: high_resolution_clock :: now () ;

    comparrisons = func ( forward < Args >( args ) ...) ;

    auto end = std :: chrono :: high_resolution_clock :: now () ;

    auto duration = std :: chrono :: duration_cast < std :: chrono :: microseconds >( end - start ) ;
    
    return duration . count () / 1000.0;
}

int main(){
    int n, k;
    cin >> n >> k;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) 
        cin >> arr[i];

    int comparrisons = 0;
    double time = measureExecutionTime(comparrisons, hybridSort, arr, 0, n - 1, k);

    for (int i = 0; i < n; i++) 
        cout << arr[i] << " ";
    cout << endl;
    cout << comparrisons << endl;
    cout << time << endl;
    

    delete[] arr;
    return 0;
}