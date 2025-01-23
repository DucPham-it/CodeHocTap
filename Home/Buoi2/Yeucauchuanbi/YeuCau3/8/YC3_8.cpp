#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
    long long n;
    bool check=true;
    cout<< "Nhap so n can kiem tra "<<endl;
    cin>>n;
    
    if (n<=1)
        {
        check=false;
        }
    else for (long long i = 2; i<=sqrt(n) ; i++) 
         {
             if (n % i ==0) 
             {       
              check=false;  
              break;                    
             }
         }

 if (check) 
    {
    cout<<n<<" la so nguyen to";
    }
 else       
    {
    cout<<n<<" khong phai la so nguyen to";
    }

    return 0;
}

