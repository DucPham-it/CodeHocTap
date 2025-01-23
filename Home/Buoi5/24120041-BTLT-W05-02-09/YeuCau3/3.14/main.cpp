#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void loadArray(ifstream &f, double a[][100], int &m, int &n);
void printArray(double a[][100], int m,int n);

int  main(){
    ifstream f ("textfile2_14.txt");
    int m,n;
    double a[100][100];
    if (!f) {
        cout<<"Can open";
        return 1;
    }
    else{
        loadArray(f,a,m,n);
        printArray(a,m,n);
        f.close();
    }

    return 0;
}

void loadArray(ifstream &f, double a[][100], int &m, int &n){
    f >> m; // Đọc số lượng hàng (m) từ tệp
    f >> n; // Đọc số lượng cột (n) từ tệp
    for (int i = 0; i < m; i++) // Duyệt qua từng hàng
        for (int j =0; j <n; j++) // Duyệt qua từng cột
            f >> a[i][j];   // Đọc giá trị thực từ tệp và lưu vào mảng a tại vị trí (i, j) 
}


void printArray(double a[][100], int m,int n){
    for (int i = 0; i < m; i++){
        for (int j =0; j <n; j++){
            cout << fixed << setprecision(2) << a[i][j];
            if (j < n-1) cout<<", ";
        }
        cout<<"\n";
    }
}
