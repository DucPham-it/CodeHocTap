#ifndef Phanso
#define Phanso

struct PS
{
    int Tu, Mau;
};

void nhapPhanSo(PS &a);
void xuatPhanSo(PS a);
PS congPhanSo(PS a, PS b); 
PS rutGonPhanSo(PS a);
int ucln(PS a);


#endif