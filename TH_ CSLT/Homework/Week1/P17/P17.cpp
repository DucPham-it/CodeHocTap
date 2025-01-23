//24120041-Phạm Võ Đức
#include <iostream>
using namespace std;

int num_Changed(unsigned int &money,int mn_be_changed)
 {
    int num=money/mn_be_changed;
    money-=num*mn_be_changed;
    return num;
 }

int main(){
    unsigned int money;
    cin >> money;
   
    cout<<"500.000:"<<num_Changed(money,500000)<<endl;
    cout<<"200.000:"<<num_Changed(money,200000)<<endl;
    cout<<"100.000:"<<num_Changed(money,100000)<<endl;
    cout<<"50.000:"<<num_Changed(money,50000)<<endl;
    cout<<"20.000:"<<num_Changed(money,20000)<<endl;
    cout<<"10.000:"<<num_Changed(money,10000)<<endl;
    cout<<"5000:"<<num_Changed(money,5000)<<endl;
    cout<<"2000:"<<num_Changed(money,2000)<<endl;
    cout<<"1000:"<<num_Changed(money,1000)<<endl;
 
 
    
    return 0;
}