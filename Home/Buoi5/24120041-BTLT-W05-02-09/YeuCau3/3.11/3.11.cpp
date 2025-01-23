/*
Hàm atoi(str1) sẽ trả về dữ liệu số nguyên chuyển đổi từ chuỗi str1
    Nếu chuyển đổi thành công sẽ trả về số nguyên được chuyển đổi
    Nếu không thành công sẽ trả về 0
    Nếu trả về được vượt quá giá trị của biến được gán hay trỏ không đúng chuỗi sẽ trả sai 

Hàm atof(str1) sẽ trả về dữ liệu số thực chuyển đổi từ chuỗi str1
    Nếu chuyển đổi thành công sẽ trả về số thực được chuyển đổi
    Nếu không thành công sẽ trả về 0
    Nếu trả về được vượt quá giá trị của biến được gán hay trỏ không đúng chuỗi sẽ trả sai 


*/

#include <iostream>
#include <string.h>
// or    <cstring>
#include <iomanip>

using namespace std;

int main(){

    char str1[100]="12345.325";
    char str2[100]="abcd";
    int i,j;
    double e,f;

    i=atoi(str1);
    j=atoi(str2);
    cout<<i<<endl; // Trả về giá trị số nguyên được chuyển đổi là 12345
    cout<<j<<endl; // Trả về 0

    e=atof(str1);
    f=atof(str2);
    cout<<fixed<<setprecision(3);
    cout<<e<<endl; // Trả về giá trị số thực được chuyển đổi là 12345.325
    cout<<f<<endl; // Trả về 0

    return 0;
}