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

SearchStats LinearSearch(int arr[], int n, int x) 
{   
    int comparisons = 0;
    for (int i = 0; i < n; i++) {   
        comparisons++;    
        if (arr[i] == x) {
            return {i, comparisons}; 
        }
        
    }
    return {-1, comparisons}; 
}

SearchStats binarySearch(int arr[], int n, int x) 
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

SearchStats jumpSearch(int arr[], int n, int x) {
    int comparisons = 0;
    int step = sqrt(n);
    int prev = 0;
    while (arr[min(step, n) - 1] < x) {
        comparisons++;
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            return {-1, comparisons};
        }
    }
    while (arr[prev] < x) {
        comparisons++;
        prev++;
        if (prev == min(step, n)) {
            return {-1, comparisons};
        }
    }
    comparisons++;
    if (arr[prev] == x) {
        return {prev, comparisons};
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
        cout << "Linear Search : " << LinearSearch(arr, n, x) << endl;
        cout << "Binary Search : " << binarySearch(arr, n, x) << endl;
        cout << "Jump Search : " << jumpSearch(arr, n, x) << endl;
        cout << endl;
    }

    delete[] arr;
    return 0;
}