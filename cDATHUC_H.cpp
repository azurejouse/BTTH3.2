#include "cDATHUC_H.h"
cDaThuc::cDaThuc(int bac){
    n = bac;
    a = new float[n + 1];
    for (int i = 0; i <= n; i++) a[i] = 0;
}
cDaThuc::~cDaThuc(){
    if (a) delete[] a;
}
/*
    - Logic: Nhập bậc của đa thức rồi cho ngườI dùng nhập cơ số ngược về ví dụ như 3 thì nhập cơ số cho mũ 3 mũ 2 mũ 1 mũ 0
*/
void cDaThuc::Nhap(){
    cout << "Nhap bac cua da thuc: ";
    cin >> n;
    if (a) delete[] a;
    a = new float[n + 1];
    for (int i = n; i >= 0; i--){
        cout << "Nhap he so cua x^" << i << ": ";
        cin >> a[i];
    }
}
/*
- Logic: Xuất dạng ax^n và xử lí các trường hợp như: 0x^n, ax^0, 1x^n, -1x^n
*/
void cDaThuc::Xuat(){
    bool isFirst = true;
    bool allZero = true;
    for (int i = n; i >= 0; i--) {
        if (a[i] == 0) continue;
        allZero = false;
        if (!isFirst && a[i] > 0) cout << " + ";
        if (a[i] < 0) cout << (isFirst ? "-" : " - ");
        float val = abs(a[i]);
        if (val != 1 || i == 0) cout << val;
        if (i > 0) {
            cout << "x";
            if (i > 1) cout << "^" << i;
        }
        isFirst = false;
    }
    if (allZero) cout << "0";
    cout << endl;
}
float cDaThuc::TinhGiaTri(float x){
    float res = 0;
    for (int i = 0; i <= n; i++) {
        res += a[i] * pow(x, i);
    }
    return res;
}
/*
    - Logic: Duyệt cái phần tử có cùng cơ số và cộng lại
*/
cDaThuc cDaThuc::Cong(cDaThuc d2){
    int maxBac = max(n, d2.n);
    cDaThuc res(maxBac);
    for (int i = 0; i <= maxBac; i++) {
        float h1 = (i <= n) ? a[i] : 0;
        float h2 = (i <= d2.n) ? d2.a[i] : 0;
        res.a[i] = h1 + h2;
    }
    return res;
}
// Tương tự với Cộng
cDaThuc cDaThuc::Tru(cDaThuc d2){
    int maxBac = max(n, d2.n);
    cDaThuc res(maxBac);
    for (int i = 0; i <= maxBac; i++) {
        float h1 = (i <= n) ? a[i] : 0;
        float h2 = (i <= d2.n) ? d2.a[i] : 0;
        res.a[i] = h1 - h2;
    }
    return res;
}