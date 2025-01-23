#include <iostream>
using namespace std;

int main() {
    int A,sum;
    A=123456;
    sum=0;
   
     while (A>0)
       {
         sum+=A%10;
         A/=10;
       }
   
    
    cout<< "Tong cac chu so cua A = "<<sum;

/* Giải thích:

    Kiểm tra điều kiện dừng của vòng : A>0 đúng hay không
    Thực hiện lệnh trong ngoặc là : 
        -Cộng giá trị của A%10 hiện tại vào Sum
        -Thay đổi gia trị của A bằng chia nguyên A/10 qua mỗi vòng lặp
    Lặp đến khi kiểm tra điều kiện A>0 không còn thỏa thì kết thúc

    
    Sum chính là giá trị của A%10 tại từng vòng lặp cộng lại 
    
    *Khá tương tự vòng for nhưng có thể dùng thêm cho các bài toán không biết giới hạn cụ thể
*/

    return 0;
}
