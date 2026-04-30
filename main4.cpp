#include "cARRAY_H.h"
int main(){
    cArray arr;
    int x;
    arr.Nhap();
    cout << "\nMang vua nhap: ";
    arr.Xuat();
    cout << "Nhap gia tri x can dem: ";
    cin >> x;
    cout << "So lan xuat hien cua " << x << " trong mang: " << arr.DemX(x) << endl;
    if (arr.KiemTraTangDan()) {
        cout << "Mang dang TANG DAN." << endl;
    } else {
        cout << "Mang KHONG tang dan." << endl;
    }
    int leMin = arr.TimLeMin();
    if (leMin == -1) {
        cout << "Khong co so le trong mang." << endl;
    } else {
        cout << "Phan tu le nho nhat la: " << leMin << endl;
    }
    int sntMax = arr.TimSNTMax();
    if (sntMax == -1) {
        cout << "Khong co so nguyen to trong mang." << endl;
    } else {
        cout << "So nguyen to lon nhat la: " << sntMax << endl;
    }
    int n = arr.getSize();
    cout << "Sap xep theo kieu Insertion Sort: ";
    arr.InsertionSort(); arr.Xuat(); arr.Reset();
    cout << "Sap xep theo kieu Merge Sort:     ";
    arr.MergeSort(0, n - 1); arr.Xuat(); arr.Reset();
    cout << "Sap xep theo kieu Quick Sort:     ";
    arr.QuickSort(0, n - 1); arr.Xuat(); arr.Reset();
    cout << "Sap xep theo kieu Heap Sort:      ";
    arr.HeapSort(); arr.Xuat(); arr.Reset();
    cout << "Sap xep theo kieu Counting Sort:  ";
    arr.CountingSort(); arr.Xuat(); arr.Reset();
    cout << "Sap xep theo kieu Radix Sort:     ";
    arr.RadixSort(); arr.Xuat();
    return 0;
}
