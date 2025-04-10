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

//Save volume in each recursion
struct SaveMinMax
{
    int min;
    int max;
    int comparisons;
};

SaveMinMax FindMinMax(int *arr, int n);
SaveMinMax FindMinMax(int *arr, int left, int right);

int main(){
    int n;
    std::cout << "Enter number of elements : ";
    std::cin >> n;
    int *arr = new int[n];
    std::cout << "Enter array : " << std:: endl;
    for (int i = 0; i < n; i++){
        std::cin >> arr[i];
    }

    SaveMinMax a = FindMinMax(arr,n);

    std::cout << "Min =" << a.min << std::endl;
    std::cout << "Max =" << a.max << std::endl;
    std::cout << "Comparisons :" << a.comparisons << std::endl;

    delete[] arr;
    return 0;
}

SaveMinMax FindMinMax(int *arr, int n){
    return FindMinMax(arr, 0, n-1);
}

SaveMinMax FindMinMax(int *arr, int left, int right){
    //if left = right in recursion return min = max
    if ((right - left) == 0){
        SaveMinMax temp = {arr[left], arr[right], 0};
        return temp;
    }
    //if just have 2 elements do comparison to find min max
    if ((right - left) == 1){
        if (arr[left] < arr[right]){
            SaveMinMax temp = {arr[left], arr[right], 1};
            return temp;
        }    
        else{
            SaveMinMax temp = {arr[right], arr[left], 1};
            return temp;
        }
    }
    
    //Device and conquer in two halves to find min max in each array
    int mid = (left + right) / 2;
    SaveMinMax leftArr = FindMinMax(arr, left, mid);
    SaveMinMax rightArr = FindMinMax(arr, mid+1, right);    

    //Find min max between left and right array and save to temp 
    SaveMinMax temp;
    if (leftArr.max > rightArr.max)
        temp.max = leftArr.max;
    else    
        temp.max = rightArr.max;

    if (leftArr.min < rightArr.min)
        temp.min = leftArr.min;
    else    
        temp.min = rightArr.min;
    
    temp.comparisons = 2 + leftArr.comparisons + rightArr.comparisons;

    return temp;
}
