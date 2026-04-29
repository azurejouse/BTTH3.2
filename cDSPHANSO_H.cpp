#include "cDSPHANSO_H.h"
cPhanSo::cPhanSo() { tu = 0; mau = 1; }
cPhanSo::cPhanSo(int t, int m) : tu(t), mau(m) {}
int cPhanSo::GCD(int a, int b) {
    return b == 0 ? abs(a) : GCD(b, a % b);
}
/*
    - Dùng pp rút gọn euler
*/
void cPhanSo::RutGon(){
    int common = GCD(tu, mau);
    tu /= common;
    mau /= common;
    if (mau < 0) { tu = -tu; mau = -mau; }
}
void cPhanSo::Nhap(){
    cin >> tu >> mau;
    if (mau == 0) mau = 1;
}
void cPhanSo::Xuat(){
    RutGon();
    if (mau == 1) cout << tu;
    else cout << tu << "/" << mau;
}
float cPhanSo::GiaTri() const{
    return (float)tu / mau;
}
int cPhanSo::getTu() const { return tu; }
cPhanSo cPhanSo::Cong(cPhanSo b) {
    cPhanSo res(tu * b.mau + b.tu * mau, mau * b.mau);
    res.RutGon();
    return res;
}
cDSPhanSo::cDSPhanSo() { n = 0; ds = nullptr; }
cDSPhanSo::~cDSPhanSo() { if (ds) delete[] ds; }

void cDSPhanSo::Nhap() {
    /* - Input: Số lượng n và n phân số.
       - Logic: Cấp phát mảng động tương tự bài Đa giác.
     */
    cout << "Nhap so luong phan so: ";
    cin >> n;
    ds = new cPhanSo[n];
    for (int i = 0; i < n; i++) {
        cout << "Nhap phan so thu " << i + 1 << " (tu mau): ";
        ds[i].Nhap();
    }
}
void cDSPhanSo::Xuat(){
    for (int i = 0; i < n; i++){
        ds[i].Xuat();
        cout << "  ";
    }
    cout << endl;
}
cPhanSo cDSPhanSo::TinhTong() {
    /* 
    - Logic: Duyệt từ đầu đến cuối, cộng dồn vào biến sum.
     */
    cPhanSo sum(0, 1);
    for (int i = 0; i < n; i++) sum = sum.Cong(ds[i]);
    return sum;
}

cPhanSo cDSPhanSo::TimMax() {
    /* 
    - Logic: lấy phần từ đầu tiên làm số lớn nhất ban đầu so sánh các số sau với m số nào lớn hơn thì gán cho m
     */
    cPhanSo m = ds[0];
    for (int i = 1; i < n; i++) {
        if (ds[i].GiaTri() > m.GiaTri()) m = ds[i];
    }
    return m;
}
    /*
    - Logic: Tương tự hàm TimMax nhưng ngược lại
    */
cPhanSo cDSPhanSo::TimMin(){
    cPhanSo m = ds[0];
    for (int i = 1; i < n; i++) {
        if (ds[i].GiaTri() < m.GiaTri()) m = ds[i];
    }
    return m;
}
/*
    - Logic: Duyệt từ i = 0 đến n, n chia hết cho số nào thì n không là số nguyên tố
*/
bool laNguyenTo(int n){
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}
cPhanSo cDSPhanSo::TimTuNguyenToMax(){
    /* 
    - Logic: Duyệt tìm phân số có tử là SNT, sau đó so sánh tìm Max.
     */
    cPhanSo maxSNT(-1, 1);
    bool timThay = false;
    for (int i = 0; i < n; i++) {
        if (laNguyenTo(ds[i].getTu())){
            if (!timThay || ds[i].getTu() > maxSNT.getTu()){
                maxSNT = ds[i];
                timThay = true;
            }
        }
    }
    return maxSNT;
}
void cDSPhanSo::SapXepTang(){
    /*
    - Logic: sử dụng selection sort
     */
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (ds[i].GiaTri() > ds[j].GiaTri()) swap(ds[i], ds[j]);
}
void cDSPhanSo::SapXepGiam(){
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (ds[i].GiaTri() < ds[j].GiaTri()) swap(ds[i], ds[j]);
}