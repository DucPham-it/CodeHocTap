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

SearchStats metaBinarySearch(int arr[], int n, int x) {
    int comparisons = 0;
    int low = 0;
    int step = 1 << (31 - __builtin_clz(n)); // 2^(floor(log2(n)))

    while (step > 0) {
        comparisons++;
        if (low + step < n && arr[low + step] <= x)
            low += step;
        step >>= 1;
    }
    comparisons++;
    if (arr[low] == x) {
        return {low, comparisons};
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
        cout << "Standard Binary Search : " << standardBinarySearch(arr, n, x) << endl;
        cout << "Meta Binary Search : " << metaBinarySearch(arr, n, x) << endl;
        cout << endl;
    }

    delete[] arr;
    return 0;
}