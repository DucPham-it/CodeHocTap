/*
Hàm sprintf ( str, format, ... ); định dạng và ghi chuỗi vào mảng ký tự str
format là định dạng cách thức để hiển thị dữ liệu
    Một số định dạng phổ biến:
        %d: Số nguyên (int)
        %f: Số thực (float/double)
        %.nf: Số thực với n chữ số thập phân
        %s: Chuỗi (string)
        %c: Ký tự (char)
        %x: Số nguyên ở dạng thập lục phân (hex)
... gồm các đối số tương ứng với số định dạng đã có ở format
*/

#include <iostream>
#include <cstdio>  

using namespace std;

int main() {
    char buffer[100];

    int i = 123;
    double d = 456.789;

    sprintf(buffer, "1/ %d 2/ %.2f", i, d);


    cout << buffer << endl;

    return 0;
}
