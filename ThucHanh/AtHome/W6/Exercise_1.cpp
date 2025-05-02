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
#include <cmath>

int findMajorityDivideConquer(const std::vector <int>&
    array , int start , int end);

int main(int argc, char const *argv[])
{
    int n;
    std::cout << "Enter number of elements :";
    std::cin >> n;
    std::vector <int> a(n);
    for (int i = 0; i < n; i++){
        std::cin >> a[i];
    }

    int finding = findMajorityDivideConquer(a, 0, n-1);
    if (finding != -1){
        std::cout << finding << std::endl;
    }
    else{
        std:: cout << "No majority element";

    }
    return 0;
}

int findMajorityDivideConquer(const std::vector <int>&
    array , int start , int end){
    if (start == end) {
        return array[start];
    }
    
    int mid = (start + end) / 2;
    int startMajority = findMajorityDivideConquer(array, start, mid);
    int endMajority = findMajorityDivideConquer(array, mid + 1, end);
    
    //If both halves agree on the majority element
    if (startMajority == endMajority) {
        return startMajority;
    }
    
    //Count occurrences of each candidate
    int startCount = 0, endCount = 0;
    for (int i = start; i <= end; i++) {
        if (array[i] == startMajority) startCount++;
        if (array[i] == endMajority) endCount++;
    }
    
    //Return the one that occurs more than half the length
    int n = end - start + 1;
    if (startCount > n / 2) {
        return startMajority;
    }
    if (endCount > n / 2) {
        return endMajority;
    }

    return -1;
}

