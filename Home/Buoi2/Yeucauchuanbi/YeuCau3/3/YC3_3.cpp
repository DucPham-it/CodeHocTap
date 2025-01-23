#include <iostream>
using namespace std;

int main() {
    int Sum=0;
    for (int i = 1; i <= 6; i++) {
        cout << "Gia tri cua i luc nay la: "<<i<<endl;
        Sum+=i;
    }
    cout <<"Tong cac so tu 1 den 6 la "<< Sum;

/* Giải thích:
    Khởi tạo biến i bắt đầu bằng 1
    Kiểm tra điều kiện dừng của vòng : i<=5 đúng hay không
    Thực hiện lệnh trong ngoặc là : cộng giá trị của i hiện tại vào Sum
    Thay đổi gia trị của i bằng i++ sau khi hoàn thành 1 vòng lặp
    Lặp đến khi kiểm tra điều kiện i<=5 không còn thỏa thì kết thúc

    Giá trị của i được in ra là gia trị lúc trong vòng lặp 
    Sum chính là giá trị của i tại từng vòng lặp cộng lại 
    
    *Dùng cho bài toán biết được giới hạn dừng cụ thể
*/
    return 0;
}
