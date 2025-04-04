// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠤⠒⠈⠉⠉⠉⠉⠒⠀⠀⠤⣀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⠁⠀⠀⠀⠀⠀⠀⢀⣄⠀⠀⠀⠀⠑⡄⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠰⠿⠿⠿⠣⣶⣿⡏⣶⣿⣿⠷⠶⠆⠀⠀⠘⠀
// ⠀⠀⠀⠀⠀⠀⠠⠴⡅⠀⠀⠠⢶⣿⣿⣷⡄⣀⡀⡀⠀⠀⠀⠀⠀⡇⠀
// ⠀⣰⡶⣦⠀⠀⠀⡰⠀⠀⠸⠟⢸⣿⣿⣷⡆⠢⣉⢀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⢹⣧⣿⣇⠀⠀⡇⠀⢠⣷⣲⣺⣿⣿⣇⠤⣤⣿⣿⠀⢸⠀⣤⣶⠦⠀⠀
// ⠀⠀⠙⢿⣿⣦⡀⢇⠀⠸⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⠀⡜⣾⣿⡃⠇⢀⣤⡀⠀
// ⠀⠀⠀⠀⠙⢿⣿⣮⡆⠀⠙⠿⣿⣿⣾⣿⡿⡿⠋⢀⠞⢀⣿⣿⣿⣿⣿⡟⠁
// ⠀⠀⠀⠀⠀⠀⠛⢿⠇⣶⣤⣄⢀⣰⣷⣶⣿⠁⡰⢃⣴⣿⡿⢋⠏⠉⠁⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠠⢾⣿⣿⣿⣞⠿⣿⣿⢿⢸⣷⣌⠛⠋⠀⠘⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠙⣿⣿⣿⣶⣶⣿⣯⣿⣿⣿⣆⠀⠇
// TRY TO FIX BUG TODAY, BECOME A NICE CODER TOMORROW !!!

// 24120041 - Pham Vo Duc

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

bool readMatrix(const char *filename, int **&matrix, int &rows, int &cols );
void writeMatrix(int **matrix, int rows, int cols);
void printMatrix ( const char * filename , int ** matrix , int rows , int cols );
void deleteMatrix(int **&matrix, int &rows, int &cols);
bool multiplyMatrices (int ** a , int aRows , int aCols ,
                       int ** b , int bRows , int bCols ,
                       int ** & res , int & resRows , int & resCols );
void transposeMatrix (int ** matrix , int rows , int cols ,
                      int ** & res , int & resRows , int & resCols );


int main(int argc, char const *argv[])
{
//  Init matrix
    int **a = nullptr;
    int aRows, aCols;
    const char fileMatrixA[] = "matrix_a.txt";
    int **b = nullptr;
    int bRows, bCols;
    const char fileMatrixB[] = "matrix_b.txt";
    int **c = nullptr;
    int cRows, cCols;
    const char fileMatrixC[] = "matrix_c.txt";
    int **cTrans = nullptr;
    int cTRows, cTCols;
    const char fileMatrixCT[] = "matrix_c_transposed.txt";
//  Assignment
    readMatrix(fileMatrixA, a, aRows, aCols);
    readMatrix(fileMatrixB, b, bRows, bCols);
    multiplyMatrices(a, aRows, aCols, b, bRows, bCols, c, cRows, cCols);
    printMatrix(fileMatrixC, c, cRows, cCols);
    transposeMatrix(c, cRows, cCols, cTrans, cTRows, cTCols);
    printMatrix(fileMatrixCT, cTrans, cTRows, cTCols);
//  Clear memory
    deleteMatrix(a, aRows, aCols);
    deleteMatrix(b, bRows, bCols);
    deleteMatrix(c, cRows, cCols);
    return 0;
}

bool readMatrix(const char *filename, int **&matrix, int &rows, int &cols)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        return false;
    }

    rows = 0;
    cols = 0;
    char line[1024];

//  Check nums of rows and cols
    int maxcols = 0;
    while (file.getline(line, 1024)) {
        int curentCols = 0;
        char* token = strtok(line, " ");
        while (token) {
            curentCols++;
            token = strtok(nullptr, " ");
        }
            rows++;
            if (maxcols < curentCols) maxcols = curentCols; 
    }  
    cols = maxcols;

//  Clear and read file again
    file.clear();
    file.seekg(0);

//  Make matrix 
    matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
//  Read matrix from file
    int row = 0;
    while (file.getline(line, 1024) && row < rows) {
    char* token = strtok(line, " ");
    int col = 0;
    while (token && col < cols) {
        matrix[row][col] = atoi(token);  
        token = strtok(nullptr, " ");
        col++;
    }
    row++;
}

    file.close();
    return true;
}
void writeMatrix(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
}
void printMatrix ( const char * filename , int ** matrix , int rows , int cols )
{
    ofstream file(filename);
    if (!file.is_open()){
        return;
    }

    for (int i = 0; i < rows; i++){
        for (int j =0; j< cols; j++){
            file << matrix[i][j] << " ";
        }
        file << endl;
    }

    file.close();
}
void deleteMatrix(int **&matrix, int &rows, int &cols)
{
    for (int i = 0; i < rows; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
    rows = 0;
    cols = 0;
    matrix = nullptr;
}
bool multiplyMatrices (int ** a , int aRows , int aCols ,
                        int ** b , int bRows , int bCols ,
                        int ** & res , int & resRows , int & resCols )
{
    if (aCols != bRows) 
        return false;
    
    resRows = aRows;
    resCols = bCols;
    res = new int*[resRows];
    for (int i = 0; i < resRows; i++){
        res[i] = new int [resCols]();
    }

    for (int i = 0; i < resRows; i++){
        for (int j =0; j < resCols; j++){
            for (int k = 0; k < aCols; k++){
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return true;
}

void transposeMatrix (int ** matrix , int rows , int cols ,
                        int ** & res , int & resRows , int & resCols )
{
    resRows = cols;
    resCols = rows;
    res = new int*[resRows];
    for (int i = 0; i < resRows; i++)
    {
        res[i] = new int [resCols];
    }
    
    for (int i = 0; i < resRows; i++){
        for (int j = 0; j < resCols; j++){
            res[i][j] = matrix[j][i];
        }
    }
}

