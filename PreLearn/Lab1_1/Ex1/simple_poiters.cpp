#include <iostream>
#include <format>
using namespace std;

void inputArray(int* &arr, int n){
  arr = new int[n]; 
  cout << "Enter Elenments: \n";

  for (int i = 0; i < n; i++){
    cout << format("arr[{}] = ", i);
    cin >> arr[i];
  }
}

void printArray(int *arr, int n){
  for (int i = 0; i < n;i++) {
    cout << format("arr[{}] = {} \n", i, arr[i]);
  }
}

int findMax(int *arr, int n){
  int max = arr[0];

  for (int i = 1; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

int sumArray(int *arr, int n){
  int sum = 0;

  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }
  return sum;
}

void concatArrays (int * a , int na , int * b , int nb , int * & res , int & nres ) {
  nres = na + nb ;
  res = new int [ nres ] ;

  for ( int i = 0 ; i < na ; i++ ) {
    res [ i ] = a [ i ] ;
  }
  for ( int j = 0 ; j < nb ; j++ ) {
    res [ na + j ] = b [ j ] ;
  } 
}

void findLongestAscendingSubarray (int * arr , int n , int * & res , int & nres )
{
  int maxLenght = 1;
  int startIndex = 0;
  int currentLength = 1;
  int currentIndex = 0;

  for (int i = 0; i < n-1; i++) {
    if ( arr[i] < arr[i+1]) {
      currentLength++;
      if (currentLength > maxLenght) {
        maxLenght = currentLength;
        startIndex = currentIndex;
      }
    }
    else {
      currentLength = 1;
      currentIndex = i+1;
    }
  }

  nres = maxLenght;
  res = new int[nres];
  for (int i = 0; i < nres; i++) {
    res[i] = arr[startIndex+i];
  }

}

int main() {
    int *a, *b, *c;
    int na, nb, nc;

    // Array a
    cout << "Enter the number of elements in array a: ";
    cin >> na;
    inputArray(a, na);

    // Array b
    cout << "Enter the number of elements in array b: ";
    cin >> nb;
    inputArray(b, nb);

    // Concatenate
    concatArrays(a, na, b, nb, c, nc);

    cout << "\nArray c (a + b): \n";
    printArray(c, nc);

    // Max
    cout << "Maximum value in c: " << findMax(c, nc) << '\n';

    // Sum
    cout << "Sum of elements in c: " << sumArray(c, nc) << '\n';

    // Longest ascending subarray
    int *asc;
    int nasc;
    findLongestAscendingSubarray(c, nc, asc, nasc);

    cout << "Longest ascending subarray in c: \n";
    printArray(asc, nasc);

    // Free memory
    delete[] a;
    delete[] b;
    delete[] c;
    delete[] asc;

    return 0;}
