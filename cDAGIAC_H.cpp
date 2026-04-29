#include "cDAGIAC_H.h"
Diem::Diem(){
     x = y = 0;
    }
void Diem::Nhap(){
    cin >> x >> y;
}
void Diem::Xuat() {
    /*
      - Logic: Để tránh(-0) hoặc số dạng (e),
      kiểm tra nếu giá trị tuyệt đối nhỏ hơn (0.0001) thì ép về 0.

     */
    float x_d = (abs(x) < 0.0001) ? 0 : x;
    float y_d = (abs(y) < 0.0001) ? 0 : y;
    cout << "(" << x_d << ", " << y_d << ")";
}
void Diem::TinhTien(float dx, float dy) {
    /*
    - Input: Độ dời dx,
    - Logic: Áp dụng công thức tịnh tiến trong mặt phẳng
     */
    x += dx; 
    y += dy;
}
void Diem::Quay(float goc) {
    /* Logic: Phép quay quanh gốc tọa độ O(0,0).
     - Đổi đơn vị góc: Radian = Goc * (PI / 180).
     - Công thức: x' = x*cos(rad) - y*sin(rad)
     - y' = x*sin(rad) + y*cos(rad)
     */
    float rad = goc * M_PI / 180.0;
    float x_old = x;
    x = x_old * cos(rad) - y * sin(rad);
    y = x_old * sin(rad) + y * cos(rad);
}

void Diem::ThayDoiTiLe(float k) {
    /*  - Logic: Phép vị tự tâm O tỉ số k.
        -Nhân tọa độ với hệ số tỉ lệ k.
     - Nếu k > 1: Đây là Phóng to.
      - Nếu 0 < k < 1: Đây là Thu nhỏ.
     */
    x *= k; 
    y *= k;
}
cDaGiac::cDaGiac(){ 
    n = 0; 
    ds = nullptr; 
}
cDaGiac::~cDaGiac() {
    if (ds) delete[] ds; 
}

void cDaGiac::Nhap() {
    /* - Input: Số lượng đỉnh n và tọa độ n đỉnh.
       - Sử dụng vòng lặp do-while để ép nhập n > 2.
       - Cấp phát động mảng
       - Gọi phương thức Nhap() của từng điểm 
     */
    do{
        cout << "Nhap so dinh da giac (n > 2): ";
        cin >> n;
    }while (n <= 2);
    ds = new Diem[n];
    for (int i = 0; i < n; i++){
        cout << "Nhap dinh " << i + 1 << ": ";
        ds[i].Nhap();
    }
}
void cDaGiac::Xuat(){
    /*
      - Logic: Duyệt qua mảng ds và sử dụng hàmXuat() của lớp Diem.
     */
    for (int i = 0; i < n; i++) {
        ds[i].Xuat();
        if (i < n - 1) cout << "; ";
    }
    cout << endl;
}
void cDaGiac::TinhTien(float dx, float dy){
    /* 
       - Logic: Duyệt danh sách,mỗi đỉnh tự thực hiện phép tịnh tiến của nó.
     */
    for (int i = 0; i < n; i++) ds[i].TinhTien(dx, dy);
}
void cDaGiac::Quay(float goc){
    /* - Logic: Duyệt mảng và quay gtri trong arr
     */
    for (int i = 0; i < n; i++) ds[i].Quay(goc);
}
void cDaGiac::ThayDoiTiLe(float k){
    /* 
      - Logic: Duyệt mảng và thay đổi tỉ lệ cho từng giá trị trong arr
     */
    for (int i = 0; i < n; i++) ds[i].ThayDoiTiLe(k);
}