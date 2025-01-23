/*
    Demo08-LoadFractionArrayFromTextFile thực hiện hàm loadFraction để đọc tử mẫu ở từng hàng và đưa vào struct Fraction từ file  
    Dùng hàm loadFractionArray để nhận độ dài n của mảng từ file và thực thi n lần hàm loadFraction 
    Cuối cùng hàm printFraction và printFractionArray với cách thức tương tự để in ra màn hình console các giá trị nhận được
*/
#include <iostream>
#include <fstream>
using namespace std;

struct Fraction{
    int num, denom;
};

void loadFraction(ifstream &f, Fraction &p);
void printFraction(Fraction p);
void loadFractionArray(ifstream &f, Fraction a[], int &n);
void printFractionArray(Fraction a[], int n);

int main(int argc, const char * argv[]) {
    Fraction a[100];
    int n = 0;
    ifstream f;
    
    f.open("fractionarray-input.txt");
    
    if(!f.is_open()){
        cout << "Can not open file" << endl;
    }
    else{
        loadFractionArray(f, a, n);
        printFractionArray(a, n);
        f.close();
    }
    return 0;
}

void loadFraction(ifstream &f, Fraction &p){
    f >> p.num;
    f >> p.denom;
}
void printFraction(Fraction p){
    cout << p.num << "/" << p.denom << endl;
}
void loadFractionArray(ifstream &f, Fraction a[], int &n){
    f >> n;
    for(int i = 0; i < n; i++){
        loadFraction(f, a[i]);
    }
}
void printFractionArray(Fraction a[], int n){
    cout << "Number of elements: " << n << endl;
    for(int i = 0; i < n; i++){
        cout << "a[" << i << "]: ";
        printFraction(a[i]);
    }
}
