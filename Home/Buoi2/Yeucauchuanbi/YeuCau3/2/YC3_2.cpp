#include <iostream>
using namespace std;

int main()
{
//Vi du if…else…
        cout << "Co di xem phim khong?" << endl;
        int money=50000;

        if (money >=100000) {
            cout <<"Tat nhien la co \n"<<endl;
             }
        else {
            cout << "Dang an mi tom day, sao ma di duoc \n"<<endl;
        }
//Khi money từ 100000 là đúng thì mới thực hiện lệnh sau if nếu không sẽ thực hiện lệnh sau else


//Vi du if…else if…else...
       cout << "Diem trung binh cua Duc la: " ;
       float GPA=8.0;
       cout << GPA <<endl;
       cout <<"Rank: ";
       
       if (GPA>= 8.5)      {
        cout << "Excellent" << endl;
    } else if (GPA >= 7.0) {
        cout << "Good" << endl;
    } else if (GPA >= 5.0) {
        cout << "Fair" << endl;
    } else                 {
        cout << "Failed" << endl;
    }
//Tương tự if…else… nhưng khi điều kiện else được thực hiện thì sẽ tiếp tục thực hiện một lệnh if…else… khác

    return 0;
}