#include "Header.h"

void loadMatrix(char inputPath[], int arr[][MAX], int& row, int& col){
    ifstream f(inputPath);
    if (f.is_open()==false){
        cout <<"Error input"<< endl;
        return;
    }
    f >> row >> col;
    for (int i=0; i<row; i++)
         for (int j=0; j<col; j++)
            f >> arr[i][j];
     
    f.close();
}

void turnLeftMatrix(int arr[][MAX], int& row, int& col){
int m=0, n=0;
int arrCpy[MAX][MAX];
     for (int i=col-1; i>=0; i--){
         for (int j=0; j<row; j++){
                arrCpy[m][n]=arr[j][i];
                n++;
         }
         n=0;
         m++;
     }
     int temp=row;
     row=col;
     col=temp;
     for (int i=0; i<row; i++)
         for (int j=0; j<col; j++) {
            arr[i][j]=arrCpy[i][j];
         }
}

void saveMatrix(char outputPath[], int arr[][MAX], int row, int col){
    ofstream f(outputPath);
    if (f.is_open()==false){
        cout <<"Error output"<< endl;
        return;
    }
    f << row << " " << col <<endl;
    for (int i=0; i<row; i++){
        for (int j=0; j<col; j++)
            f << arr[i][j] << " ";
        f << endl;
    }
    f.close();
}
