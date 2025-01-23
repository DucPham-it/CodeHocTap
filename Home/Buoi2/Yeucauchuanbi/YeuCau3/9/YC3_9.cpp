#include <iostream>
using namespace std;

int main()
{
//Ví dụ với toán tử || và kỹ thuật đoản mạch (short-circuit evaluation)
cout << "Co nen yeu co lon hon minh 20 tuoi khong ?"<<endl;
    bool have_G63=1, beauty=rand()%2;
   
    if ((have_G63) || (beauty)) 
    {
      cout<<"Tat nhien roi \n"<<endl;
    }
    else
    {
      cout<<"Khong \n"<<endl; 
    }
//Chỉ cần have_G63 trả giả trị true thì ((have_G63) || (beauty)) tự trả giá trị true mà không cần đánh giá qua beauty cho nên kết quả luôn là in ra Tat nhien roi



//Ví dụ với toán tử && và kỹ thuật đoản mạch (short-circuit evaluation)
cout << "Co nen yeu som khong ?"<<endl;
    bool haveMoney=0, Funny=rand()%2;
    if ((haveMoney) && (Funny)) 
    {
      cout<<"Co ngay";
    }
    else 
    {
       cout<<"Khong, lo hoc di"; 
    }
//Chỉ cần haveMoney trả giả trị false thì ((haveMoney) && (Funny)) tự trả giá trị false mà không cần đánh giá qua Funny cho nên kết quả luôn là in ra Khong, lo hoc di
   
    return 0;
}