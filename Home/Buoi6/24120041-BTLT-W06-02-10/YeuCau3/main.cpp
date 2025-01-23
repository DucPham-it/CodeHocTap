#include "Header.h"

int main(){
    int arr1[MAX], arr2[MAX];
    int n1,n2;
    char inputPath[]="NUMBER.TXT";
    char outputPath[]="PRIME.TXT";
    loadArray(inputPath, arr1, n1);
    primeNumberArray(arr1, arr2, n1, n2);
    saveArray(outputPath, arr2, n2);
    return 0;
}