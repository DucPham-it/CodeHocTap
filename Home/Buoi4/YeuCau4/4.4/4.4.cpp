/*
index nằm ngoài phạm vị mảng thì không hợp lệ
*/
#include <iostream>
using namespace std;

int main(){
    
    int arrayA[5]={1,2,3,4,5};
    cout<<arrayA[-5]; //Sai vì mảng bắt đầu từ 0
    cout<<arrayA[5]; //Sai vì mảng có 5 phần tử thì index chỉ tới 4
    return 0;
}
