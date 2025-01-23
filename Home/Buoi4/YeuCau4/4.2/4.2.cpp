/*
Lấy số phần tử cho mảng ta sử dụng sizeof(mảng)/sizeof(của 1 phần tử hay của kiểu dữ liệu)
    với sizeof là hàm để tính dung lượng bộ nhớ.
*/
#include <iostream>
using namespace std;

int main(){
    
    int arrayA[5];
    cout<<sizeof(arrayA)/sizeof(int); //Kết quả là 5
    return 0;
}
