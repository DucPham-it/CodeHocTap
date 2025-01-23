/*
    Demo07-SaveFractionArrayToTextFile thực hiện hàm inputFraction để đọc tử mẫu ở từng hàng và đưa vào struct Fraction từ màn hình console
    Dùng hàm inputFractionArray để nhận độ dài n của mảng từ console và thực thi n lần hàm inputFraction để nhập mảng 
    Cuối cùng hàm saveFraction và saveFractionArray với cách thức tương tự để lưu giá trị vào file
*/
#include <iostream>
#include <fstream>
using namespace std;

struct Fraction{
    int num, denom;
};

void inputFraction(Fraction &p);
void saveFraction(ofstream &f, Fraction p);
void inputFractionArray(Fraction a[], int &n);
void saveFractionArray(ofstream &f, Fraction a[], int n);

int main(){
    Fraction a[100];
    int n = 0;
    ofstream f;  // Hàm ofstream để mở file để ghi qua biến f

    
    inputFractionArray(a, n);
    f.open("fractionarray-output.txt"); // Mở file để ghi
    if(!f.is_open()){                   // Kiểm tra file đã mở chưa nhằm tránh lỗi
        cout << "Can not create file" << endl;
    }
    else{
        saveFractionArray(f, a, n); // thực hiện hàm lưu dữ liệu mảng vào  file

        f.close();
    }
    return 0;
}

void inputFraction(Fraction &p){ //Hàm nhập tử mẫu của struct p từ bàn phím 
    cout << "Numerator: ";
    cin >> p.num;
    cout << "Denominator: ";
    cin >> p.denom;
}

void saveFraction(ofstream &f, Fraction p){ // Hàm lưu dữ liệu tử mẫu của struct p vào file
    f << p.num << " " << p.denom << endl;
}

void inputFractionArray(Fraction a[], int &n){ // Hàm nhập dữ liệu từ bàn phím
    cout << "Number of elements: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        cout << "a[" << i << "]: " << endl;
        inputFraction(a[i]);
    }
}

void saveFractionArray(ofstream &f, Fraction a[], int n){ // Hàm lưu dữ liệu mảng vào file
    f << n << endl; // Đưa số lượng phần tử n và dấu xuống dongf
    for(int i = 0; i < n; i++){
        saveFraction(f, a[i]); // Thực hiện lưu vào file từng struct a index i
    }
}
