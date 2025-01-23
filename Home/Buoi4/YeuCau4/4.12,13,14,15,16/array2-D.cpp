/*
    Khai bao array:     <Kiểu dữ liệu> <Tên mảng>[<Kích thước hàng>] [<kích thước cột>];

    Lấy số phần tử cho mảng 2 chiều ta dùng sử dụng: sizeof(mảng)/sizeof(của 1 phần tử hay của kiểu dữ liệu)
    với sizeof là hàm để tính dung lượng bộ nhớ.

    Lấy 1 phần tử ở dòng i, cột j trong mảng 2 chiều ta dùng <Tên mảng>[i][j]
*/

#include <iostream>
#define MAXROW 100
#define MAXCOL 100
using namespace std;

void  inputMatrix(double a[][100], int &nrows, int &ncols){ 
    cout<<"Nhap so dong cua mang: ";
    cin>>nrows;
    cout<<"Nhap so cot cua mang: ";
    cin>>ncols;
    for (int i=0;i<nrows;i++)
        for (int j=0;j<ncols;j++){
        cout<<"Phan tu thu ["<<i<<","<<j<<"]"<<" la: ";
        cin>>a[i][j];
    }
}

void outputMatrix(double a[][100], int nrows, int ncols){
    for (int i=0;i<nrows;i++)
            for (int j=0;j<ncols;j++){
            cout<<"Gia tri phan tu thu ["<<i<<","<<j<<"]"<<" la: "<<a[i][j]<<endl;
            }
}


int main()
{
    int a[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}}; //Khai bao array
    int b=sizeof(a)/sizeof(int); //b=12 số phần tủ của mảng (3,4)
    cout<<"So phan tu mang a la"<<b<<endl;
    cout<<"Gia tri cua mang a tai dong 2 cot 1 la: "<<a[2][1]<<endl;
  
    double c[MAXROW][MAXCOL];
    int nrows, ncols;
    inputMatrix(c,nrows,ncols);
    outputMatrix(c,nrows,ncols);
    
    return 0;
}
