// 24120041 - Pham Vo Duc

#include <iostream>
using namespace std;

void inputArray (int * & arr , int n );
void printArray (int * arr , int n );
int findMax (int* arr , int n );
int sumArray (int* arr , int n );
void concatArrays (int * a , int na , int * b , int nb , int * & res , int & nres );
void findLongestAscendingSubarray (int * arr , int n , int * & res , int & nres );

int main(){
    
    cout << "Enter the number of elements in array a: ";
    int na;
    cin >> na;
    int * a = new int[na];
    inputArray(a, na);
    
    cout << "Enter the number of elements in array b: ";
    int nb;
    cin >> nb;
    int * b = new int[nb];
    inputArray(b, nb);

    int nc;
    int *c = NULL;

    concatArrays(a, na, b, nb, c, nc);
    cout << "Max element in array c: " << findMax(c, nc) << endl;
    cout << "Sum of elements in array c: " << sumArray(c, nc) << endl;

    int nres;
    int *res = NULL;
    findLongestAscendingSubarray(c, nc, res, nres);
    cout << "Longest ascending subarray in array c: ";
    printArray(res, nres);

    delete [] a;
    delete [] b;
    delete [] c;
    delete [] res;

    return 0;
}

void inputArray (int * & arr , int n ){
    for (int i = 0; i < n; i++){
        cout << "Enter element " << i << ": ";
        cin >> arr[i];
    }
}

void printArray (int * arr , int n ){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int findMax (int* arr , int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

int sumArray (int* arr , int n) {
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += arr[i];
    }
    return sum;
}

void concatArrays (int * a , int na , int * b, int nb, int * & res , int & nres){
    nres = na + nb;
    res = new int[nres];
    for (int i = 0; i < na; i++){
        res[i] = a[i];
    }
    for (int i = 0; i < nb; i++){
        res[na + i] = b[i];
    }
}

void findLongestAscendingSubarray (int * arr , int n , int * & res , int & nres ){
    int max = 1;
    int count = 1;
    int start = 0;

    for (int i = 1; i < n; i++){
        if (arr[i] > arr[i - 1]){
            count++;
        } else {
            if (count > max){
                max = count;
                start = i - count;
            }
            count = 1;
        }
    }
    if (count > max){
        max = count;
        start = n - count;
    }
    nres = max;
    res = new int[nres];
    for (int i = 0; i < nres; i++){
        res[i] = arr[start + i];
    }
}
