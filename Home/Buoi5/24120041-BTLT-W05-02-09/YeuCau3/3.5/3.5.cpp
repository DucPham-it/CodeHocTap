/*
Hàm strcpy(str2,str1) sẽ sao chép chuỗi thứ nhất vào chuỗi thứ hai (Điều kiện chuỗi thứ hai phải đủ không gian để chứa)
*/

#include <iostream>
#include <string.h>
// or    <cstring>

using namespace std;

int main(){

    char str1[100]="Hello ";
    char str2[100]="World!";
    strcpy(str2,str1); // "Hello" được chèn vào st2 và thế World!
    cout<<str2;
    return 0;
}