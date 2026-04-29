#include "cARRAY_H.h"   
int main(){
    cArray arr;
    int x;
    arr.Nhap();
    cout << "\nMang vua nhap: ";
    arr.Xuat();
    cout << "\nNhap gia tri x can dem: ";
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
    arr.SapXepTang();
    cout << "Mang sau khi sap xep: ";
    arr.Xuat();
    return 0;
}