#include "Header.h"

int main(){
    int a[MAX][MAX];
    int m,n;
    char inputPath[]="MATRIX.TXT";
    char outputPath[]="OUTPUT.TXT";

    loadMatrix(inputPath,a,m,n);
    turnLeftMatrix(a,m,n);
    saveMatrix(outputPath,a,m,n);
    return 0;
}