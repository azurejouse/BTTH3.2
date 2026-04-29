#ifndef CDSPHANSO_H
#define CDSPHANSO_H
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class cPhanSo{
private:
    int tu, mau;
public:
    cPhanSo();
    cPhanSo(int t, int m);
    void Nhap();
    void Xuat();
    float GiaTri() const;
    int getTu() const;
    int getMau() const;
    static int GCD(int a, int b);
    void RutGon();
    cPhanSo Cong(cPhanSo b);
};
class cDSPhanSo {
private:
    int n;
    cPhanSo *ds;
public:
    cDSPhanSo();
    ~cDSPhanSo();
    void Nhap();
    void Xuat();
    cPhanSo TinhTong();
    cPhanSo TimMax();
    cPhanSo TimMin();
    cPhanSo TimTuNguyenToMax();
    void SapXepTang();
    void SapXepGiam();
};
bool laNguyenTo(int n);
#endif