#include <iostream>
#include <random>
#include <vector>

using namespace std;

void makeRandomArray(vector<int>& vec, int n, int k) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<>dis(0, k);
    for (int& num : vec) {
        num = dis(gen);
    }
}
void findMax(vector<int>& vec, int n, int &max) {
  if (n < 1)
       return;
  if (vec[n] > max)
    max = vec[n];
  findMax(vec, n - 1, max);
}

void printRows(int j, int i) {
    if (j > i)
        return;
    cout << j;
    printRows(j+1, i);
}

void printThreeAngle(int i, int k) {
    if (i > k)
        return;
    printRows(1, i);
    cout << endl;
    printThreeAngle(i+1, k);
}

int findNumTo1(int n) {
    if ( n == 1) return 1;
    if (n % 2 == 0) return findNumTo1(n/2);
    else return findNumTo1((n+1)/2);
}

int main() {
    vector<int> vec(20);
    makeRandomArray(vec, 20, 1000);
    int max  = vec[0];
    for (int i = 0; i < vec.size(); i++) {
      cout << vec[i] << " ";
    }
    cout << endl;

    findMax(vec, 19, max);
    cout << "max = " << max << endl;
    printThreeAngle(1, 5);
}