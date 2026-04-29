#include "cDAGIAC_H.h"
int main(){
    cDaGiac dg;
    dg.Nhap();
    cout << "\nDa giac ban dau: "; 
    dg.Xuat();
    float dx, dy;
    cout << "Nhap vector tinh tien (dx dy): ";
    cin >> dx >> dy;
    dg.TinhTien(dx, dy);
    cout << "Ket qua sau tinh tien: ";
    dg.Xuat();
    float goc;
    cout << "Nhap goc quay (do): ";
    cin >> goc;
    dg.Quay(goc);
    cout << "Ket qua sau khi quay: ";
    dg.Xuat();
    float k_phong;
    cout << "Nhap he so phong to (k > 1): ";
    cin >> k_phong;
    dg.ThayDoiTiLe(k_phong);
    dg.Xuat();
    float k_thu;
    cout << "Nhap he so thu nho (0 < k < 1): ";
    cin >> k_thu;
    dg.ThayDoiTiLe(k_thu);
    dg.Xuat();
    return 0;
}