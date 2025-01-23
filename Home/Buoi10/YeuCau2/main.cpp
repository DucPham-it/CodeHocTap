#include "Header.h"

int main(){
    int N;
    cout << "Creat Pascal Triangle of N = ";
    cin >> N;
    int** matrix = creatPascalTriangle(N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << matrix[i][j] <<" ";
        }
        cout << endl;
    }
    for (int i = 0; i < N; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}
