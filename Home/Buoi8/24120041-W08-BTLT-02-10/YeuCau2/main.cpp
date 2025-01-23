#include <iostream>
using namespace std;

void input2DArray(int **&a, int &nrows, int &ncols){
   cout << "Nhap so dong: ";
   cin >> nrows;
   cout << "Nhap so cot: ";
   cin >> ncols;
  
   a = new int*[nrows];
   for(int i = 0; i < nrows; i++){
       a[i] = new int[ncols];
   }


   for(int i = 0; i < nrows; i++){
       for(int j = 0; j < ncols; j++){
           cout << "Nhap phan tu thu [" << i << "," << j << "] : ";
           cin >> a[i][j];
       }
   }
}

void inputArray(int *&a, int &n){
   cout << "Nhap so phan tu: ";
   cin >> n;

   a = new int[n];
   for(int i = 0; i < n; i++){
       cout << "Nhap phan tu thu " << i <<" :";
       cin >> a[i];
   }
}

bool checkArrayInRows1(int **a, int rows, int cols, int ncols, int *b, int k){
    
    if (cols + k > ncols) return 0;

        for (int i=0; i<k; i++){
            if (a[rows][cols+i] != b[i]){
                return 0;
            }
        }
    
    return 1;
}
bool checkArrayInRows2(int **a, int rows, int cols, int *b, int k){

    if (cols - (k-1) < 0) return 0;

        for (int i=k-1; i>=0 ; i--){
            if (a[rows][cols-(k-1-i)] != b[k-1-i]){
                return 0;
            }
        }
    
    return 1;
}
bool checkArrayInCols1(int **a, int rows, int cols, int nrows, int *b, int k){
   
    if (rows + k > nrows) return 0;

        for (int i=0; i<k; i++){
            if (a[rows+i][cols] != b[i]){
                return 0;
            }
        }

    return 1;
}
bool checkArrayInCols2(int **a, int rows, int cols, int *b, int k){
    
    if (rows - (k-1) < 0) return 0;

        for (int i=k-1; i>=0 ; i--){
            if (a[rows-(k-1-i)][cols] != b[k-1-i]){
                return 0;
            }
        }

    return 1;
}

int countArrayInMatrix(int **a, int nrows, int ncols, int *b, int k){
    int count = 0;
    for (int i = 0; i < nrows; i++)
        for (int j = 0; j < ncols; j++){
            if (checkArrayInRows1(a,i,j,ncols,b,k)) count++;
            if (checkArrayInCols1(a,i,j,nrows,b,k)) count++;
            if (checkArrayInRows2(a,i,j,b,k)) count++;
            if (checkArrayInCols2(a,i,j,b,k)) count++;
        }
    return count;
}

int main(){
   int **matrix;
   matrix = nullptr;
   int nrows = 0;
   int ncols = 0;


   int *a;
   a = nullptr;
   int n = 0;


   input2DArray(matrix, nrows, ncols);
   inputArray(a, n);

   int count= countArrayInMatrix(matrix, nrows, ncols, a, n);

   cout << "Mang A xuat hien " << count << " lan";

   delete []a;
   a = nullptr;
   n = 0;


   for(int i = 0; i < nrows; i++){
       delete []matrix[i];
   }
   delete []matrix;

    return 0;
}