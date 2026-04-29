#ifndef CDATHUC_H
#define CDATHUC_H
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
class cDaThuc{
private:
    int n;
    float *a;
public:
    cDaThuc(int bac = 0);
    ~cDaThuc();
    void Nhap();
    void Xuat();
    float TinhGiaTri(float x);
    cDaThuc Cong(cDaThuc d2);
    cDaThuc Tru(cDaThuc d2);
};
#endif