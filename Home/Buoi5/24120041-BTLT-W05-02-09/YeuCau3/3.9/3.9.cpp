/*
Hàm strstr(str1,str2) sẽ kiểm tra str2 có nằm trong str1 hay không.
Nếu có sẽ trỏ đến vị trí đầu tiên chứa str2
Nếu không trả về NULL
*/

#include <iostream>
#include <string.h>
// or    <cstring>

using namespace std;

int main(){

    char str1[100]="Hello, I'm Depp. Nice to see you, John.";
    char str2[100]="Depp";
    cout<<  strstr(str1,str2);  // Trỏ đến vị trí chưá Depp... 
    return 0;
}