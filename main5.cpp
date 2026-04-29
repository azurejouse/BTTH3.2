#include "cDATHUC_H.h"
int main(){
    cDaThuc d1, d2;
    d1.Nhap();
    d2.Nhap();
    cout << "\nDa thuc 1: "; d1.Xuat();
    cout << "Da thuc 2: "; d2.Xuat();
    float x;
    cout << "\nNhap gia tri x: "; cin >> x;
    cout << "Gia tri P1(" << x << ") = " << d1.TinhGiaTri(x) << endl;
    cDaThuc tong = d1.Cong(d2);
    cout << "Tong hai da thuc: "; tong.Xuat();
    cDaThuc hieu = d1.Tru(d2);
    cout << "Hieu hai da thuc: "; hieu.Xuat();
    return 0;
}