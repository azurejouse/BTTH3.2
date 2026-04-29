#include "cTAMGIAC_H.h"
int main(){
    cTamGiac tg;
    tg.Nhap();
    cout << "Toa do ban dau: "; tg.Xuat();
    cout << "Loai tam giac: "; tg.PhanLoai();
    cout << "Chu vi: " << tg.TinhChuVi() << " | Dien tich: " << tg.TinhDienTich() << endl;
    tg.TinhTien();
    cout << "Ket qua sau tinh tien: "; tg.Xuat();
    tg.Quay();
    cout << "Ket qua sau khi quay: "; tg.Xuat();
    tg.PhongTo();
    cout << "Ket qua sau phong to: "; tg.Xuat();
    tg.ThuNho();
    cout << "Ket qua sau thu nho: "; tg.Xuat();
    return 0;
}