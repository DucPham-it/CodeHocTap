// ⣿⣿⣿⣿⣿⣿⠀⠀⠀⠈⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⠉⠁⠀⣿
// ⣿⣿⣿⣿⣿⣿⣧⡀⠀⠀⠀⠀⠙⠿⠿⠿⠻⠿⠿⠟⠿⠛⠉⠀⠀⠀⠀⠀⣸⣿
// ⣿⣿⣿⣿⣿⣿⣿⣷⣄⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿
// ⣿⣿⣿⣿⣿⣿⣿⣿⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⣴⣿⣿⣿⣿
// ⣿⣿⣿⣿⣿⣿⣿⣿⡟⠀⠀⢰⣹⡆⠀⠀⠀⠀⠀⠀⣭⣷⠀⠀⠀⠸⣿⣿⣿⣿
// ⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠈⠉⠀⠀⠤⠄⠀⠀⠀⠉⠁⠀⠀⠀⠀⢿⣿⣿⣿
// ⣿⣿⣿⣿⣿⣿⣿⣿⢾⣿⣷⠀⠀⠀⠀⡠⠤⢄⠀⠀⠀⠠⣿⣿⣷⠀⢸⣿⣿⣿
// ⣿⣿⣿⣿⣿⣿⣿⣿⡀⠉⠀⠀⠀⠀⠀⢄⠀⢀⠀⠀⠀⠀⠉⠉⠁⠀⠀⣿⣿⣿
// ⣿⣿⣿⣿⣿⣿⣿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⣿
// ⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿
// WHEN I SEE THE ASSIGNMENT THAT MY LECTURER GAVE !!!


//24120041 - Pham Vo Duc

#include <iostream>
using namespace std;

struct SortStats {
    int comparisons ;
    int swaps ;
};

SortStats insertionSort (int arr [] , int n ) ;

int main () {
    int arr [] = {5 , 2 , 4 , 6 , 1 , 3};
    int n = sizeof ( arr ) / sizeof ( arr [0]) ;
    
    SortStats stats = insertionSort ( arr , n ) ;
    
    cout << " Sorted array : ";
    for (int i = 0; i < n ; i ++)
    cout << arr [ i ] << " ";
    cout << endl ;
    
    cout << " Comparisons : " << stats . comparisons << endl ;
    cout << " Swaps : " << stats . swaps << endl ;
    
    return 0;
}

SortStats insertionSort (int arr [] , int n ) {
    SortStats temp;
    temp.comparisons = 0;
    temp.swaps = 0;
    for (int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
            temp.swaps++;
            temp.comparisons++;
        }
        arr[j + 1] = key;  
        if (j >= 0){
            temp.comparisons++;
        }
    }
    return temp;
}

