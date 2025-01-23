/*
Hàm strcmp(str1,str2) Hàm này bắt đầu so sánh ký tự đầu tiên của 2 chuỗi str1 và str2 theo bangr max ASCII
Nếu chúng bằng nhau, hàm sẽ tiếp tục với các cặp sau cho đến khi các ký tự khác nhau hoặc cho đến khi đạt đến kết thúc (kí tự Null).
Giá trị trả về: 
<0 nếu str1 không khớp và bé hơn str2
0 nếu str1 khớp str2
>0 nếu str1 không khớp và lớn hơn str2
*/


#include <iostream>
#include <string.h>
// or    <cstring>
#include <ctype.h>
using namespace std;

void toUpperCase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

void toLowerCase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}
int main(){

    char str1[100]="Hello Duc";
    char str2[100]="Hello duc";
    char str3[100]="Xin chao";
    char str4[100]="xin Chao";

/*
    Ví dụ dùng hàm strcmp() để so sánh chữ thường chữ hoa:
    Note: Trong bảng mã ASCII thì chữ hoa có giá trị nhỏ hơn chữ thường
*/
    cout<<strcmp(str1,str2)<<endl; // Quét đên cặp 'D' và 'd' thì 'D' là 068 bé hơn 'd' là 100 nên trả giá trị <0

/*
    Ví dụ dùng hàm strcmp() để so sánh không tính chữ thường chữ hoa:
    ta dùng hàm toupper() hoặc to tolower() để chuyển cả 2 về 1 dạng với thư viên <ctype.h>
*/
    toUpperCase(str1);
    toUpperCase(str2);
    cout<<strcmp(str1,str2)<<endl; // Cả 2 chuỗi giờ đây "HELLO DUC" bằng nhau sẽ trẻ về 0;

    toLowerCase(str3);
    toLowerCase(str4);
    cout<<strcmp(str3,str4)<<endl; // Cả 2 chuỗi giờ đây "xin chao" bằng nhau sẽ trẻ về 0;

    return 0;
}