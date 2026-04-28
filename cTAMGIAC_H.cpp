#include "cTAMGIAC_H.h"
void Diem::Nhap(){
    cin >> x >> y;
}
 /* - Input: Khoảng cách dời dx, dy.
    - Output: Tọa độ x, y mới
    - Logic: x = x + dx; y = y + dy;
 */
void Diem::TinhTien(float dx, float dy) {
    x += dx;
    y += dy;
}
/*
   - Input: Góc quay
   - Output: Tọa độ sau khi xoay.
   - Logic: Áp dụng công thức xoay tọa độ.
 */
void Diem::Quay(float goc) {
    float rad = goc * 3.141592654 / 180.0;
    float x_old = x;
    float y_old = y;
    x = x_old * cos(rad) - y_old * sin(rad);
    y = x_old * sin(rad) + y_old * cos(rad);
}
void Diem::ThayDoiTiLe(float k){
    x *= k;
    y *= k;
}
float Diem::TinhKhoangCach(Diem khac){
    return sqrt(pow(x - khac.x, 2) + pow(y - khac.y, 2));
}
cTamGiac::cTamGiac(){}
void cTamGiac::Nhap() {
    cout << "Nhap A: "; A.Nhap();
    cout << "Nhap B: "; B.Nhap();
    cout << "Nhap C: "; C.Nhap();
}
void Diem::Xuat(){
    float x_display = x;
    float y_display = y;
    if (abs(x_display) < 0.0001) x_display = 0;
    if (abs(y_display) < 0.0001) y_display = 0;
    cout << "(" << x_display << ", " << y_display << ")";
}
void cTamGiac::Xuat(){
    A.Xuat(); cout << "; "; 
    B.Xuat(); cout << "; "; 
    C.Xuat();
    cout << endl;
}
/*
   - Input: 3 đỉnh A, B, C.
   - Output: Tổng độ dài 3 cạnh.
 */
float cTamGiac::TinhChuVi() {
    return A.TinhKhoangCach(B) + B.TinhKhoangCach(C) + C.TinhKhoangCach(A);
}
/*- Input: 3 cạnh a, b, c.
   - Output: Diện tích theo công thức Heron.
 */
float cTamGiac::TinhDienTich(){
    float a = B.TinhKhoangCach(C), b = A.TinhKhoangCach(C), c = A.TinhKhoangCach(B);
    float p = TinhChuVi() / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
/* - Input: 3 cạnh a, b, c.
   - Logic: Kiểm tra điều kiện tam giác -> Kiểm tra Đều -> Cân -> Vuông (Pytago)
   - Output: Các thể loại tam giác
 */
void cTamGiac::PhanLoai(){
    float a = B.TinhKhoangCach(C), b = A.TinhKhoangCach(C), c = A.TinhKhoangCach(B);
    if (a + b <= c || a + c <= b || b + c <= a) cout << "Khong phai tam giac";
    else if (a == b && b == c) cout << "Tam giac deu";
    else if (a == b || b == c || a == c) cout << "Tam giac can";
    else if (abs(a*a+b*b-c*c) < 0.1 || abs(a*a+c*c-b*b) < 0.1 || abs(b*b+c*c-a*a) < 0.1) cout << "Tam giac vuong";
    else cout << "Tam giac thuong";
    cout << endl;
}
void cTamGiac::TinhTien(){
    float dx, dy;
    cout << "Nhap dx, dy: "; cin >> dx >> dy;
    A.TinhTien(dx, dy); B.TinhTien(dx, dy); C.TinhTien(dx, dy);
}
void cTamGiac::Quay(){
    float goc;
    cout << "Nhap goc quay: "; cin >> goc;
    A.Quay(goc); B.Quay(goc); C.Quay(goc);
}
/*
  - Input: k
 - Logic: Nhân tọa độ các đỉnh với k (phóng) hoặc 1/k (thu)
 */
void cTamGiac::PhongTo() {
    float k;
    cout << "Nhap he so phong k: "; cin >> k;
    A.ThayDoiTiLe(k); B.ThayDoiTiLe(k); C.ThayDoiTiLe(k);
}

void cTamGiac::ThuNho(){
    float k;
    cout << "Nhap he so thu k: "; cin >> k;
    if(k != 0) { A.ThayDoiTiLe(1/k); B.ThayDoiTiLe(1/k); C.ThayDoiTiLe(1/k); }
}