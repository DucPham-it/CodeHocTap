
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
#include <cstdlib>
#include <vector>
#include <ctime>
#include <random>

using namespace std;

enum class PivotStrategy{
    FIRST_ELEMENT ,
    MIDDLE_ELEMENT ,
    MEDIAN_OF_THREE ,
    RANDOM_ELEMENT
};

void writeArray(vector<int> &arr);
int medianOfThree(int a, int b, int c);
void quickSort(vector<int> &arr, int left, int right, PivotStrategy pivotStrategy);

int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    vector<int> arr(n);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<>dis(0, n);
    for (int& num : arr) {
        num = dis(gen);
    }

    vector<int> vec = arr;
    quickSort(vec, 0, vec.size() - 1, PivotStrategy::FIRST_ELEMENT);
    writeArray(vec);

    vec = arr;
    quickSort(vec, 0, vec.size() - 1, PivotStrategy::MIDDLE_ELEMENT);
    writeArray(vec);

    vec = arr;
    quickSort(vec, 0, vec.size() - 1, PivotStrategy::MEDIAN_OF_THREE);
    writeArray(vec);

    vec = arr;
    quickSort(vec, 0, vec.size() - 1, PivotStrategy::RANDOM_ELEMENT);

    writeArray(vec);

    return 0;
}

void writeArray(vector<int> &arr){
    for (int i=0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int medianOfThree(int a, int b, int c){
    if (a < b && b < c){
        return b;
    }
    else if (a < c && c < b){
        return c;
    }
    return a;
}

void quickSort(vector<int> &arr, int left, int right, PivotStrategy pivotStrategy){
    int pivot;
    if (pivotStrategy == PivotStrategy::FIRST_ELEMENT){
        pivot = arr[left];
    }
    else if (pivotStrategy == PivotStrategy::MIDDLE_ELEMENT){
        pivot = arr[(left + right) / 2];
    }
    else if (pivotStrategy == PivotStrategy::MEDIAN_OF_THREE){
        int mid = (left + right) / 2;
        pivot = medianOfThree(arr[left], arr[mid], arr[right]);
    }
    else if (pivotStrategy == PivotStrategy::RANDOM_ELEMENT){
        srand(time(0));
        int random = rand() % (right - left + 1) + left;
        pivot = arr[random];
    }
    int i = left, j = right;
    do{
       while (arr[i] < pivot) i++;
       while (arr[j] > pivot) j--;
       if (i <= j){
           swap(arr[i], arr[j]);
           i++;
           j--;
       }
    }while(i < j);
    if (left < j){
        quickSort(arr, left, j, pivotStrategy);
    }
    if (i < right){
        quickSort(arr, i, right, pivotStrategy);
    }
}

