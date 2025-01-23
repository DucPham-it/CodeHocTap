#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

struct Package
{
    char maDonHang[18];
    char tenNguoiNhan[16];
    char diaChi[51];
    char sdt[11];
    double khoiLuong;
};

void taiDanhSach(char path[], Package *a, int &n){
    ifstream f(path);
    if (!f) {
        cout << "Loi mo file input" << endl;
        return;
    }
    char  line[100];
    n=0;
    f.getline(line,100);
    while (f.peek() != EOF){
        f.get(a[n].maDonHang,18,'|');
        f.ignore();
        f.get(a[n].tenNguoiNhan,16,'|');
        f.ignore();
        f.get(a[n].diaChi,51,'|');
        f.ignore();
        f.get(a[n].sdt,11,'|');
        f.ignore();
        f >> a[n].khoiLuong;
        f.ignore();
        n++;
    }
    f.close();
}

void inDanhSach(char path[], char deliveryDist[], Package *a, int n){
    ofstream f(path);
    if (!f) {
        cout << "Loi mo file output" << endl;
        return;
    }
    f << "Ma don hang|Ten nguoi nhan|Dia chi|So dien thoai|Khoi luong \n"; 
    for (int i=0; i<n; i++){
        if (strstr(a[i].diaChi, deliveryDist) != NULL){
        f << a[i].maDonHang << "|";
        f << a[i].tenNguoiNhan << "|";
        f << a[i].diaChi << "|";
        f << a[i].sdt << "|";
        f << a[i].khoiLuong << "\n";
        }
    }
    f.close();
}

int main(){
    char input[]="input.txt";
    char output[]="output.txt";
    Package *a = new Package[1000];
    int n;

    taiDanhSach(input, a, n);

    char deliveryDist[51];
    cout << "Dia chi quan can loc : ";
    cin >> deliveryDist;

    inDanhSach(output, deliveryDist, a, n);

    delete[] a; 
    return 0;
}