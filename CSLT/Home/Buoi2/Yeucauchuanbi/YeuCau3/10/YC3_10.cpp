#include <iostream>
using namespace std;

int main()
{
int Emergency;
    cout<<"Nhap so dien thoai khan cap can goi "<<endl;
    cin>>Emergency;

    switch (Emergency)
    {
    case 111:
        cout<<"Lien he tong dai quoc gia ve bao ve tre em"; break;
    case 112:
        cout<<"Lien he tong dai tro giup tim kiem va cuu nan"; break;
    case 113:
        cout<<"Lien he canh sat"; break;
    case 114:
        cout<<"Lien he cuu hoa"; break;
    case 115:
        cout<<"Lien he cuu thuong"; break;
    default:
        cout<<"Khong nam trong danh sach so dien thoai khan cap. Vui long nhap lai"; break;
    }
    return 0;
}
/*Giải thích:
    Khi nhập dữ liệu đúng với một trong các số của case thì sẽ thực hiện lệnh của case đó và dùng break để thoát khỏi case 
        Ví dụ: input: 113
               ouput: Lien he canh sat
    Khi dữ liêu nhập khác với các dữ liệu trong case thì sẽ thực hiện lệnh của default
        Ví dụ: input: 422
               ouput: Khong nam trong danh sach so dien thoai khan cap. Vui long nhap lai
*/