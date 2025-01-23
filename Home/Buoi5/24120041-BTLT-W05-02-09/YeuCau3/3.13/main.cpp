#include <iostream>
#include <iomanip>
#include <fstream> // THư viện hỗ trợ nhập xuất với file
using namespace std;

int main()
{
   ofstream f ("textfile2_13.txt");   // mở file để nhập với ofstream qua biến f
   if (!f){                           // kiểm tra file có mở được không để tránh lỗi        
     cout<<"Can't open";
     return 1;
   }
   double a[3][3]={ // khai báo và khởi tạo mảng 2 chiều
    {1.1,2.2,3.3},
    {4.4,5.5,6.6},
    {7.7,8.8,9.9}
   };

    for (int i = 0; i < 3; i++) // duyệt qua từng hàng của mảng
    {
        for (int j = 0; j < 3; j++) // duyệt qua từng cột của mảng
        {
            f << fixed << setprecision(2) << a[i][j]; // Đưa  giá trị vào file qua  f, tương tự cout của iostream 
            if (j < 3 - 1) f << ", "; // thêm dấu phẩy và khoảng trắng sau mỗi giá trị, trừ giá trị cuối cùng của hàng
        } 
    }
        f << endl;  // thêm dấu xuống dòng sau mỗi hàng
    }

    f.close(); // đóng file qua biến  f
    return 0;
}