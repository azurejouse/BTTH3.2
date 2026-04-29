#include "cNHANVIENSX_H.h"
int main(){
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    vector<cNhanVienSX> ds(n);
    for (int i = 0; i < n; i++){
        cout << "\nNhap nhan vien thu " << i + 1 << ":" << endl;
        ds[i].Nhap();
    }
    cout << "\nDanh Sach Nhan Vien: " << endl;
    for (int i = 0; i < n; i++){
        ds[i].Xuat();
    }
    // Liet ke tat ca nhan vien Luong thap nhat
    double minLuong = ds[0].TinhLuong();
    for (int i = 1; i < n; i++) {
        if (ds[i].TinhLuong() < minLuong) minLuong = ds[i].TinhLuong();
    }
    cout << "\n(Cac) nhan vien luong thap nhat (" << (size_t)minLuong << " VND):" << endl;
    for (int i = 0; i < n; i++) {
        if (ds[i].TinhLuong() == minLuong) ds[i].Xuat();
    }
    double tong = 0;
    for (int i = 0; i < n; i++) {
        tong += ds[i].TinhLuong();
    }
    cout << "\nTong luong cong ty phai tra: " << (size_t)tong << " VND" << endl;
    //So ngay/thang/nam
    cNhanVienSX giaNhat = ds[0];
    for (int i = 1; i < n; i++) {
        if (ds[i].getNam() < giaNhat.getNam()) giaNhat = ds[i];
        else if (ds[i].getNam() == giaNhat.getNam()) {
            if (ds[i].getThang() < giaNhat.getThang()) giaNhat = ds[i];
            else if (ds[i].getThang() == giaNhat.getThang()) {
                if (ds[i].getNgay() < giaNhat.getNgay()) giaNhat = ds[i];
            }
        }
    }
    cout << "\n(Cac) nhan vien tuoi cao nhat:" << endl;
    for (int i = 0; i < n; i++){
        if (ds[i].getNam() == giaNhat.getNam() && 
            ds[i].getThang() == giaNhat.getThang() && 
            ds[i].getNgay() == giaNhat.getNgay()) {
            cout << "- " << ds[i].getHoTen() << " (Sinh ngay: " << ds[i].getNgay() 
                 << "/" << ds[i].getThang() << "/" << ds[i].getNam() << ")" << endl;
        }
    }
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(ds[i].TinhLuong() > ds[j].TinhLuong()) {
                cNhanVienSX temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
    cout << "\nDanh Sach Sap Xep: " << endl;
    for(int i = 0; i < n; i++){
        ds[i].Xuat();
    }
    return 0;
}