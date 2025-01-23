/*
    Sự khác nhau của Pass-by-value và Pass-by-reference:
        Pass-by-value:
            Giá trị đối số được truyền cho hàm.
            Hàm chỉ nhận được bản sao gía trị.
            Đối số thực không đổi.
            Đối số là: biến, hằng số, biểu thức.

        Pass-by-reference:
            Đối số thực được truyền cho hàm.
            Hàm nhận được đối số gốc.
            Đối số thực có thể được thay đổi.
            Đối số chỉ là biến.

*/
#include <iostream>
using namespace std;

int opposite1(int a){
    a=a*-1;
    return a;
}

int opposite2(int& a){
    a=a*-1;
    return a;
}

int main()
{
    int a=5;

    cout<<"Pass-by-value:"<<endl;
    cout<<"OPP1: "<<opposite1(a)<<endl<<"a now: "<<a<<endl<<endl;
    // Giá trị opposite1 trả về là số a khi đã (-1) song a vẫn giữ giá trị 5

    cout<<"Pass-by-reference:"<<endl;
    cout<<"OPP2: "<<opposite2(a)<<endl<<"a now: "<<a<<endl;
     // Giá trị opposite2 trả về cũng là số a khi đã (-1) song a đã thay đổi thành a*(-1)
    return 0;
}
