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

SearchStats standardBinarySearch(int arr[], int n, int x) 
{
    int comparisons = 0;
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        comparisons++;
        int mid = left + (right - left) / 2;
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

SearchStats metaBinarySearch(int arr[], int n, int x)
{
    int comparisons = 0;
    int low = 0;sentinelLinearSearch
    int step = pow(2, floor(log2(n))); 

    while (step > 0) {
        comparisons++;
        if (low + step < n && arr[low + step] <= x) {
            low += step;
        }
        step /= 2; 
    }
    
    if (arr[low] == key)
        return {low, comparisions};
    retrun {-1, comparisions};
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
        cout << "Standard Binary Search : " << standardBinarySearch(arr, n, x) << endl;
        cout << "Meta Binaryx Search : " << metaBinarySearch(arr, n, x) << endl;
        cout << endl;
    }

    delete[] arr;
    return 0;
}