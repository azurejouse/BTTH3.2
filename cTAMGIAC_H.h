#ifndef cTAMGIAC_H 
#define cTAMGIAC_H
#include <iostream>
#include <cmath>
using namespace std;
class Diem{
private:
    float x; 
    float y;
public:
    void Nhap(); 
    void Xuat(); 
    void TinhTien(float dx, float dy);
    void Quay(float goc);
    void ThayDoiTiLe(float k); // k > 1 là phóng, k < 1 là thu
    float TinhKhoangCach(Diem khac);
};
class cTamGiac{
private:
    Diem A;
    Diem B;
    Diem C;
public:
    cTamGiac();
    void Nhap();
    void Xuat();
    float TinhChuVi();
    float TinhDienTich();
    void PhanLoai();
    void TinhTien();
    void Quay();
    void PhongTo();
    void ThuNho(); 
};
#endif