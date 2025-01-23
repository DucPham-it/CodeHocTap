//24120041-Phạm Võ Đức
#include <iostream>
using namespace std;

int main(){
    int plate,sum,Nut;
    cin >> plate;
    sum=0;
   
     while (plate>0)
       {
         sum+=plate%10;
         plate/=10;
       }
   
    Nut=sum%10;

    cout<<Nut;
    
    return 0;
}