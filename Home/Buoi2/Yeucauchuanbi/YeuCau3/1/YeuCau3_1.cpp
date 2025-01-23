#include <iostream>
using namespace std;

int main()
{
//Vi du toan tu &&
        cout << "Ban duc co duoc di xe phan khoi lon khong ?" << endl;
        int Age=18;
        bool License=1;

        if ((Age>=18) && (License)) {
            cout <<"Tat nhien la co \n"<<endl;
             }
        else {
            cout << "Ban Duc chua duoc \n" <<endl;
        }
//Phai thoa ca hai dieu kien moi tra ve dung


//Vi du toan tu ||
       cout << "Ban Duc co nguoi yeu duoc khong ? " <<endl;
       bool handsome=1, rich=0;
       
       if ((handsome) || (rich) )    {
        cout << "Tat nhien la duoc" << endl;
    } else                 {
        cout << "E truong ton" << endl;
    }
//Can thoa it nhat mot dieu kien

    return 0;
}