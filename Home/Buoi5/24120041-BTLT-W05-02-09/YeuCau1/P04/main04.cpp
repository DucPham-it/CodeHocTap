#include "P04.h"
#define MAX 1000
int main(){

    date a[MAX];
    int N;
    inputArray(a,N);
    arrange(a,N);
    printArray(a,N);

    return 0;
}