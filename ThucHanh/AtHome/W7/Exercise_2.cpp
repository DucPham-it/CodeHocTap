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
#include <vector>
using namespace std;

const int CUTOFF = 10;

void insertionSort ( std :: vector <int >& arr , int left , int right) ;
bool isSorted ( const std :: vector <int >& arr , int left , int right);
void merge ( std :: vector <int >& source , std :: vector <int >& dest , int left ,
           int mid , int right);
void mergeSortRecursive ( std :: vector <int >& source , std :: vector <int >& dest ,
int left , int right) ;
void mergeSort ( std :: vector <int >& arr) ;

int main(int argc, char const *argv[]){
    vector <int > arr = {12 , 11 , 13 , 5 , 6 , 7};

    cout << " Original array : ";
    for ( int num : arr ) {
        cout << num << " ";
    }
    cout << endl;

    mergeSort ( arr ) ;

    cout << " Sorted array : ";
    for ( int num : arr ) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

void insertionSort (vector <int>& arr , int left , int right)
{
    for (int i = left + 1; i <= right; i++){
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key){
           arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

bool isSorted (vector <int>& arr , int left , int right)
{
    for (int i = left; i < right; i++){
        if (arr[i] > arr[i + 1])
              return false;
        }
    return true;
}

void merge (vector <int>& source , vector <int>& dest , int left ,
           int mid , int right)
{
    int i = left, j = mid+1, k = left;
    while (i <= mid && j <= right ){
        if (source[i] <= source[j]){
            dest[k++] = source[i++];
        }
        else{
            dest[k++] = source[j++];
        }

    }
    while (i <= mid) {
        dest[k++] = source[i++];
    }
    while (j <= right) {
        dest[k++] = source[j++];
    }
    for (i = left; i <= right; i++){
        source[i] = dest[i];
    }
}

void mergeSortRecursive (vector <int>& source , vector <int>& dest ,
                        int left , int right)
{
    if (left < right){
    int mid = (left + right) / 2;
    mergeSortRecursive(source, dest, left, mid);
    mergeSortRecursive(source, dest, mid + 1, right);
    merge(source, dest, left, mid, right);
    }
}

void mergeSort (vector <int>& arr)
{
    if (isSorted(arr, 0, arr.size() - 1)) {
        return;
    }
    if (arr.size() <= CUTOFF){
        insertionSort(arr, 0, arr.size() - 1);
        return;
    }
    vector <int> dest(arr.size());
    mergeSortRecursive(arr, dest, 0, arr.size() - 1);
}