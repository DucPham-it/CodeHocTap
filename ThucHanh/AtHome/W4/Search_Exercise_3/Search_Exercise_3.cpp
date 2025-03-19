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
using namespace std;

struct SearchStats {
    int comparisons ;
    int index;
};

typedef struct SearchStats SearchStats;

ostream & operator << (ostream & output, const SearchStats & searchStats) {
    output << searchStats.index << " " << searchStats.comparisons;
    return output;
}

SearchStats standardLinearSearch(int arr[], int n, int x) 
{   
    int comparisons = 0;
    for (int i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == x) {
            return {comparisons, i}; 
        }
    }
    return {comparisons, -1}; 
}

SearchStats sentinelLinearSearch(int arr[], int n, int x)
{
    int comparisons = 0;
    int last = arr[n -1];
    arr[n - 1] = x;
    int i = 0;
    while (arr[i] != x) {
        comparisons++;
        i++;
    }

    arr[n - 1] = last;
    comparisons++;
    if (i < n - 1 || arr[n - 1] == x) {
        return {comparisons, i};
    }
    return {comparisons, -1};
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
        cout << "Standard Linear Search : " << standardLinearSearch(arr, n, x) << endl;
        cout << "Sentinel Linear Search : " << sentinelLinearSearch(arr, n, x) << endl;
        cout << endl;
    }

    delete[] arr;
    return 0;
}