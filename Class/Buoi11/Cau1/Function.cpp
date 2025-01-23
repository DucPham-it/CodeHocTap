#include "Header.h"

void findBuffalo(){
    for (int i = 0; i <= 20 ; i++)
    {
        for (int j = 0; j <= 33; j++ )
        {
            if (100-i-j>=0 && 5*i+3*j+((double)(100-i-j))/3==100)
            {
                cout << "Trau dung: " << i << "; ";
                cout << "Trau nam: " << j << "; ";
                cout << "Trau gia: " << 100-i-j << endl;
            }
        }    
    }
    
}