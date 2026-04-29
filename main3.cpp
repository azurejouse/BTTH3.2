#include "cDSPHANSO_H.h"
int main(){
    cDSPhanSo ds;
    ds.Nhap();
    ds.Xuat();
    cPhanSo tong = ds.TinhTong();
    cout << "\nTong cac phan so trong danh sach: ";
    tong.Xuat();
    cout << endl;
    cPhanSo max = ds.TimMax();
    cPhanSo min = ds.TimMin();
    cout << "Phan so lon nhat: "; max.Xuat(); cout << endl;
    cout << "Phan so nho nhat: "; min.Xuat(); cout << endl;
    cPhanSo sntMax = ds.TimTuNguyenToMax();
    if (sntMax.getTu() == -1) {
        cout << "Khong co phan so nao co tu la so nguyen to." << endl;
    } else {
        cout << "Phan so co tu la so nguyen to lon nhat: ";
        sntMax.Xuat();
        cout << endl;
    }
    ds.SapXepTang();
    cout << "Sap xep tang dan: ";
    ds.Xuat();
    ds.SapXepGiam();
    cout << "Sap xep giam dan: ";
    ds.Xuat();
    return 0;
}