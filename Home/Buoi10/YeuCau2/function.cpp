#include "Header.h"

int** creatPascalTriangle(int N){
    int **p = new int*[N];
    for (int i=0; i<N; i++){
        p[i] = new int[i+1];
    }
    for (int i = 0; i < N; i++){
        p[i][0]= 1;
        p[i][i] = 1;
    }
    for (int i = 2; i < N; i++){
        for (int j = 1; j < i; j++){
            p[i][j]= p[i-1][j-1] + p[i-1][j];
        }
    }
    return p;
}