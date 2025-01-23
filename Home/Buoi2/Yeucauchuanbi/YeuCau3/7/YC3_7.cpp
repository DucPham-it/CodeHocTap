#include <iostream>
using namespace std;

int main() {

    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
           continue;          
        }
        cout<< i << endl;
    }
    cout<<"Day la cac so le trong doan tu 1 den 10";
    return 0;
}

/* Giải thích:

    Vòng lặp diễn ra và thực hiện lệnh in số i
    khi lệnh continue được thực hiện sẽ dừng ngay vòng lặp nó thuộc về  , các lệnh phía sau trong vòng lặp hiện tại không được thực thi mà qua vòng lặp tiếp theo
    Tiếp tục thực thi chương trình ở bên ngoài khối lệnh hoặc vòng lặp đó.
*/