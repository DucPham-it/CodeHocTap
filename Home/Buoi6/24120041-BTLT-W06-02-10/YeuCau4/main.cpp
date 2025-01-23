#include "header.h"

int main(){
    char inputPath[]="OPERATION.TXT";
    char outputPath[]="RESULT.TXT";
    operation arr[MAX];
    int n;
    loadOpe(inputPath, arr, n);
    saveResult(outputPath, arr, n);
    return 0;
}