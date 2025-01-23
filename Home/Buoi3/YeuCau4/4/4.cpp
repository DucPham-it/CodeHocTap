/*
    1. Sự khác nhau của local variable và global variable
    Global variable:
    -Được khai báo bên ngoài các hàm (bao gồm cả hàm main() ).
    -Có thể truy xuất từ mọi nơi trong chương trình, ngoài trừ nơi có biến trùng tên. (Vẫn có thể truy bằng cách dùng toán tử  ::).
    Local variable:
    -Được khai báo bên trong một khối lệnh.
    -Chỉ có thể lưu tạm thời các giá trị trong nội bộ của một khối lệnh.

    2. Không nên sử dụng global variable vì tránh những lỗi logic về việc dùng chung biến trong chương trình gây khó hiểu.
     
*/
#include <iostream>
int global=4;
using namespace std;

void POW(int a){
    int two=2, P=1; // local variable in function
    for (int i=1;i<=two;i++){
            P=P*a;
    }
    cout<<"Global can be here :"<<global<<endl;
    cout<<"P ="<<P<<endl;
}
int main()
{
    int local=2; // Local variable in main
    POW(local);
    cout<<"global also be here: "<<global;

    return 0;
}