#ifndef cNHANVIENSX_H
#define cNHANVIENSX_H
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class cNhanVienSX{
private:
    string sMaNV, sHoTen;
    int iNgay, iThang, iNam;
    int iSoSP;
    double dDonGia;
public:
    cNhanVienSX();
    void Nhap();
    void Xuat();
    double TinhLuong() const;
    int TinhTuoi() const;
    string getHoTen() const { return sHoTen; }
    int getNgay() const { return iNgay; }
    int getThang() const { return iThang; }
    int getNam() const { return iNam; }
};
#endif