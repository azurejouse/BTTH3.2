#ifndef CARRAY_H
#define CARRAY_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
class cArray{
private:
    int n;
    int *a;
    int *backup;
public:
    cArray(int size = 0);
    ~cArray();
    void Nhap();
    void Xuat();
    void Reset();
    int getSize() { return n; }
    int DemX(int x);
    bool KiemTraTangDan();
    int TimLeMin();
    bool laSNT(int n);
    int TimSNTMax();
    void InsertionSort();
    void MergeSort(int l, int r);
    void QuickSort(int l, int r);
    void HeapSort();
    void CountingSort();
    void RadixSort();
    void merge(int l, int m, int r);
    void heapify(int n, int i);
    int getMax();
};
#endif
