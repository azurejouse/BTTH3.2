#ifndef CARRAY_H
#define CARRAY_H
#include <iostream>
#include <algorithm>
using namespace std;
class cArray{
private:
    int n;
    int *a;
public:
    cArray();
    ~cArray();
    void Nhap();
    void Xuat();
    int DemX(int x);
    bool KiemTraTangDan();
    int TimLeMin();
    int TimSNTMax();
    void SapXepTang(); 
};
bool laSNT(int n);
#endif