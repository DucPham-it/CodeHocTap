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
#include <cmath>
using namespace std;

struct SearchStats {
    int index;
    int comparisons ;
};

typedef struct SearchStats SearchStats;

ostream & operator << (ostream & output, const SearchStats & searchStats) {
    output << searchStats.index << " " << searchStats.comparisons;
    return output;
}

SearchStats ternarySearch(int arr[], int left, int right, int x) {
    int comparisons = 0;

    while (left <= right) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;
        
        comparisons++; 
        if (arr[mid1] == x) return {mid1, comparisons};

        comparisons++;  
        if (arr[mid2] == x) return {mid2, comparisons};

        comparisons++;  
        if (x < arr[mid1]) {
            right = mid1 - 1;
        } else {
            comparisons++; 
            if (x > arr[mid2]) {
                left = mid2 + 1;
            } else {
                left = mid1 + 1;
                right = mid2 - 1;
            }
        }
    }
    return {-1, comparisons};
}

SearchStats BinarySearch(int arr[], int n, int x) 
{
    int comparisons = 0;
    int left = 0;
    int right = n - 1;
    while (left <= right) {       
        int mid = left + (right - left) / 2;
        comparisons++;
        if (arr[mid] == x) {
            return {mid, comparisons};
        }
        if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return {-1, comparisons};
}

int main()
{
    int n, q;
    cin >> n >> q;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i =0; i < q; i++) {
        cout << endl;
        int x;
        cin >> x;
        cout << "Binary Search : " << BinarySearch(arr, n, x) << endl;
        cout << "Ternary Search : " << ternarySearch(arr, 0, n - 1, x) << endl;
        cout << endl;
    }

    delete[] arr;
    return 0;
}