#include <iostream>
using namespace std;

int main() {
    int A,sum;
    A=123456;
    sum=0;
   
     do {
        sum+=A%10;
         A/=10;
     }
     while (A>0);
    
    cout<< "Tong cac chu so cua A = "<<sum;

/* Giải thích:
   
    
    Thực hiện lệnh trong ngoặc là : 
        -Cộng giá trị của A%10 hiện tại vào Sum
        -Thay đổi gia trị của A bằng chia nguyên A/10 qua mỗi vòng lặp
    Kiểm tra điều kiện dừng của vòng : A>0 đúng hay không
    Lặp đến khi kiểm tra điều kiện A>0 không còn thỏa thì kết thúc

    
    Sum chính là giá trị của A%10 tại từng vòng lặp cộng lại 
    
    *Khá tương tự vòng while nhưng sẽ thực hiện lệnh trước rồi mới kiểm tra điều kiện sau nên thứ tự các lệnh trong ngoặc sẽ có khác biệt
    , tùy vào bài sẽ sử dụng cho phù hợp
*/

    return 0;
}
