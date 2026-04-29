#include "cNHANVIENSX_H.h"
cNhanVienSX::cNhanVienSX(){
    iNgay = iThang = iNam = iSoSP = 0;
    dDonGia = 0;
}
void cNhanVienSX::Nhap(){
    cin.ignore();
    cout << "Nhap Ma NV: "; getline(cin, sMaNV);
    cout << "Nhap Ho Ten: "; getline(cin, sHoTen);
    cout << "Nhap Ngay Thang Nam sinh: "; cin >> iNgay >> iThang >> iNam;
    cout << "Nhap so san pham: "; cin >> iSoSP;
    cout << "Nhap don gia: "; cin >> dDonGia;
}
void cNhanVienSX::Xuat(){
    cout << "ID: " << sMaNV << " | Ten: " << sHoTen 
         << " | NS: " << iNgay << "/" << iThang << "/" << iNam
         << " | Luong: " << (size_t)TinhLuong() << " VND" << endl;
}
double cNhanVienSX::TinhLuong() const{
    return iSoSP * dDonGia;
}
int cNhanVienSX::TinhTuoi() const{
    // Gia su nam hien tai la 2026
    return 2026 - iNam;
}