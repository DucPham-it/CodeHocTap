/*
Hàm strcat(str1,str2) ghép chuỗi thứ hai vào cuối chuỗi đầu tiên ( Yêu cầu chuỗi đầu đủ không gian)
*/

#include <iostream>
#include <string.h>
// or    <cstring>

using namespace std;

int main(){

    char str1[100]="Hello ";
    char str2[100]="World!";
    strcat(str1,str2);
    cout<<str1;
    return 0;
}