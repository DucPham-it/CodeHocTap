#include <iostream>
using namespace std;

int main() {
    int j;
    for (int i = 1; i <= 10; i++) {
        if (i == 5) {
           j=i; 
           break; 
           cout <<" so j "<< j <<endl;   
        }
        cout << "so i la "<< i << endl;
    }
    cout<<"Vong lap da ket thuc tai i="<<j;

    return 0;
}

/* Giải thích:

    Vòng lặp diễn ra và thực hiện lệnh in số i
    khi lệnh break được thực hiện sẽ dừng ngay vòng lặp nó thuộc về, các lệnh phía sau trong vòng lặp không được thực thi
    Tiếp tục thực thi chương trình ở bên ngoài khối lệnh hoặc vòng lặp đó.
*/
