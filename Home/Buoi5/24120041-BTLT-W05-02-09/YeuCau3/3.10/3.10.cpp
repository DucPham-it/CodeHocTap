/*
Hàm strtok(str1,str2) sẽ tách các chuỗi str1 thành các phần với các kí tự trong str2 là vách ngăn;
Giải thích hoạt động:
Khi gọi hàm thì hàm sẽ  trỏ đầu của chuỗi dến vị trí trỏ bắt đầu có chứa từ của str2 nằm trong str1 và thay thế kí tự đó bằng \0(NULL) khi đó chuỗi trả về 
gồm đúng phần cần tách. 
Trong các lần tiếp theo nếu ta để tham số NULL thì mặc định sẽ bắt đầu lấy từ con trỏ NULL của chuỗi đang quét để tiếp tục tìm vị trí trỏ bắt đầu 
của các kí tự trong str2.
Mãi cho đến khi đến cuối chuỗi không còn gì để trích xuất thì trả về NULL. Từ sau lần này thì strtok không còn trỏ hợp lệ để quét nữa.
*/

#include <iostream>
#include <string.h>
// or    <cstring>

using namespace std;

int main(){

    char str1[100]="Hello, I'm Depp. Nice to see you, John.";

    char *token = strtok(str1, " .");

    while (token != NULL) {
        
        cout << token << endl;
        token = strtok(NULL, " .");
        if (token==NULL) cout<<"NULL"<<endl;
        
    }
    
    return 0;
}