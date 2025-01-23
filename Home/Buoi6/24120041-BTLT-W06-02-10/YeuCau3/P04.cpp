#include "Header.h"

void loadArray(char inputPath[], int arr[], int& n){
    ifstream f(inputPath);
    if (f.is_open()==false){
        cout <<"Error input"<< endl;
        return;
    }
    n=0;
    while (f.peek() != EOF){
        f >> arr[n];
        n++;
    }
     
    f.close();
}

bool primeNumber(int n){
    if (n==1) return 0;
    for (int i=2; i<=sqrt(n); i++)
            if (n%i==0) return 0;
    return 1;
}

void primeNumberArray(int arr[],  int primeArray[], int n, int& count){
    count=0;
    for (int i=0; i<n; i++)
        if (primeNumber(arr[i])) {
            primeArray[count]=arr[i];
            count++;
        }
}

void saveArray(char outputPath[], int arr[], int n){
    ofstream f(outputPath);
    if (f.is_open()==false){
        cout <<"Error output"<< endl;
        return;
    }
    for (int i=0; i<n; i++)
        f << arr[i] << " ";
    f.close();
}


