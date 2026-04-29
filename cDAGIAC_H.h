#ifndef CDAGIAC_H
#define CDAGIAC_H
#include <iostream>
#include <cmath>
using namespace std;
class Diem{
private:
    float x, y;
public:
    Diem();
    void Nhap();
    void Xuat();
    void TinhTien(float dx, float dy);
    void Quay(float goc);
    void ThayDoiTiLe(float k);
};
class cDaGiac{
private:
    int n;
    Diem *ds;
public:
    cDaGiac();
    ~cDaGiac();
    void Nhap();
    void Xuat();
    void TinhTien(float dx, float dy);
    void Quay(float goc);
    void ThayDoiTiLe(float k);
};
#endif