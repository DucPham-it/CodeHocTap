#include "PhanSo.h"

int main()
{
    PS So_1,So_2;
    nhapPhanSo(So_1);
    nhapPhanSo(So_2);
    xuatPhanSo(rutGonPhanSo(congPhanSo(So_1,So_2)));
    return 0;
}