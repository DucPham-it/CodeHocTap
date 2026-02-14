#include <iostream>
#include <fstream> 
#include <sstream>
#include <string>
using namespace std;

bool readMatrix ( const char * filename , int ** & matrix , int & rows , int & cols );
void printMatrix ( const char * filename , int ** matrix , int rows , int cols );
bool multiplyMatrices (int ** a , int aRows , int aCols ,
int ** b , int bRows , int bCols ,
int ** & res , int & resRows , int & resCols ) ;
void transposeMatrix (int ** matrix , int rows , int cols ,
int ** & res , int & resRows , int & resCols ) ;
void deleteDynamicMatrix (int ** matrix , int rows , int cols ) ;


int main() {
  int **a = nullptr, **b = nullptr, **c = nullptr, **ct = nullptr;
  int aRows, aCols, bRows, bCols, cRows, cCols, ctRows, ctCols;

  // Read matrix A
  if (!readMatrix("matrix_a.txt", a, aRows, aCols)) {
    cout << "Failed to read matrix A\n";
    return 1;
  }

  // Read matrix B
  if (!readMatrix("matrix_b.txt", b, bRows, bCols)) {
    cout << "Failed to read matrix B\n";
    deleteDynamicMatrix(a, aRows, aCols);
    return 1;
  }

  // Multiply A and B → C
  if (!multiplyMatrices(a, aRows, aCols,
                        b, bRows, bCols,
                        c, cRows, cCols)) {
    cout << "Matrix multiplication failed\n";
    deleteDynamicMatrix(a, aRows, aCols);
    deleteDynamicMatrix(b, bRows, bCols);
    return 1;
  }

  // Print matrix C
  printMatrix("matrix_c.txt", c, cRows, cCols);

  // Transpose C → Ct
  transposeMatrix(c, cRows, cCols, ct, ctRows, ctCols);

  // Print transposed matrix
  printMatrix("matrix_c_transposed.txt", ct, ctRows, ctCols);

  // Free memory
  deleteDynamicMatrix(a, aRows, aCols);
  deleteDynamicMatrix(b, bRows, bCols);
  deleteDynamicMatrix(c, cRows, cCols);
  deleteDynamicMatrix(ct, ctRows, ctCols);

  return 0;
}


bool readMatrix ( const char * filename , int ** & matrix , int & rows , int & cols ) {
  ifstream in(filename);
  if (!in.is_open()) 
    return false;

  rows = 0;
  cols = -1;
  matrix = nullptr;

  int** temp = nullptr;
  string line;

  while (getline(in, line)) {
    if (line.empty()) return false;

    // count elements in this row
    int count = 0;
    int value;
    stringstream ss(line);

    while (ss >> value) count++;

    if (!ss.eof() || count == 0) return false;

    if (cols == -1)
      cols = count;
    else if (count != cols)
      return false;

    // allocate new row
    int* row = new int[cols];
    ss.clear();
    ss.str(line);

    for (int i = 0; i < cols; i++)
      ss >> row[i];

    // grow matrix
    int** newMatrix = new int*[rows + 1];
    for (int i = 0; i < rows; i++)
      newMatrix[i] = temp[i];

    newMatrix[rows] = row;

    delete[] temp;
    temp = newMatrix;
    rows++;
  }

  if (rows == 0) return false;

  matrix = temp;

  return true;
}

void printMatrix ( const char * filename , int ** matrix , int rows , int cols ) {
  ofstream out(filename);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      out << matrix[i][j];
      if (j < cols - 1)
        out << " ";
    }
    out << "\n";
  }
}

bool multiplyMatrices (int ** a , int aRows , int aCols ,
int ** b , int bRows , int bCols ,
int ** & res , int & resRows , int & resCols ) {
  if (aCols != bRows)
    return false;

  resRows = aRows;
  resCols = bCols;

  res = new int*[resRows];

  for (int i = 0; i < resRows; i++) {
    res[i] = new int[resCols];

    for (int j = 0; j < resCols; j++) {
      res[i][j] = 0;
      for (int k = 0; k < aCols; k++) {
        res[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  return true;
} 

void transposeMatrix (int ** matrix , int rows , int cols ,
int ** & res , int & resRows , int & resCols ) {
  resRows = cols;
  resCols = rows;
  
  res = new int*[resRows];

  for (int i = 0; i < resRows; i++){
    res[i] = new int[resCols];
    for (int j = 0; j < resCols; j++){
      res[i][j] = matrix[j][i];
    }
  }
}

void deleteDynamicMatrix(int ** matrix , int rows , int cols ) {
  for (int i = 0; i < rows; i++){
    delete[] matrix[i];
  }
  delete[] matrix;
}
