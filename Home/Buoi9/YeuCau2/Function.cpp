#include "Header.h"

void readBinaryFile(polynomial* poly, int& count){
    ifstream f("POLY.BIN", ios::binary);
    if (!f.is_open()){
        cout << " ERROR OPEN TO READ" << endl;
        return;
    }
    count = 0;
    while ( f.read((char*)&poly[count].n,sizeof(int16_t)) )
    {
        poly[count].mono = new monomial[poly[count].n];
        for (int i = 0; i < poly[count].n ; i++)
        {
            f.read((char*)&poly[count].mono[i], sizeof(monomial));
        } 
        count++;       
    }
   f.close(); 
}

