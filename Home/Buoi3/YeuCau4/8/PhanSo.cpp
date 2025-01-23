#include "PhanSo.h"
#include <iostream>
#include <sstream>
using namespace std;


void nhapPhanSo(PS &a){
    char line[100];
    cout<<"Nhap tu va mau so: ";
    do {
        cin.getline(line,100);

    } while (!(stringstream(line)>>a.Tu>>a.Mau) || (a.Mau == 0));
}


PS congPhanSo(PS a, PS b){
    PS r;
    r.Tu=(a.Tu*b.Mau)+(b.Tu*a.Mau); 
    r.Mau=a.Mau*b.Mau;
    return r;
}

int ucln(PS a){
     while (a.Mau!= 0) {
        int mind = a.Tu % a.Mau;
        a.Tu = a.Mau;
        a.Mau = mind;
    }
    return a.Tu;
}

PS rutGonPhanSo(PS a){
    PS r;
    int mind=ucln(a);
    r.Tu=a.Tu/mind;
    r.Mau=a.Mau/mind;
    return r;
}

void xuatPhanSo(PS a){
    if (a.Mau==1) cout<<"Ket Qua:"<<a.Tu;
    else {
        if (a.Tu==a.Mau) cout<<"Ket Qua: "<<a.Tu/a.Mau;
        else cout<<"Ket Qua: "<<a.Tu<<"/"<<a.Mau;
    }
}


