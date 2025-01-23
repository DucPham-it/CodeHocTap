/*
Hàm strlen(str1) trả về độ dài của chuỗi kí tự str1;
Khi sử dụng thì strlen sẽ có giá trị là số kí tự có trong chuỗi
*/

#include <iostream>
#include <string.h>
// or    <cstring>
using namespace std;

int main()
{
    char* lengthOfStr="";
    strcat(lengthOfStr,"Xin chao tat ca"); //15 ki tu
    cout<<strlen(lengthOfStr); // In ra 15
    return 0;
}