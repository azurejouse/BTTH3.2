#include "cARRAY_H.h"
cArray::cArray(){
    n = 0;
    a = nullptr;
}
cArray::~cArray(){
    if(a) delete[] a;
}
void cArray::Nhap(){
    cout << "Nhap so luong phan tu n: ";
    cin >> n;
    if (n <= 0) return;
    a = new int[n];
    for (int i = 0; i < n; i++){
        cout << "Nhap phan tu a[" << i << "]: ";
        cin >> a[i];
    }
}
void cArray::Xuat(){
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}
/* - Logic: Duyệt mảng chỗ nào có x thì cập nhật count++
*/
int cArray::DemX(int x){
    int count = 0;
    for (int i = 0; i < n; i++) if (a[i] == x) count++;
    return count;
}
/*
- Logic: check số kế tiếp có nhỏ hơn kông không thì false, ngược lại thì trả về true
*/
bool cArray::KiemTraTangDan(){
    if (n <= 1) return true;
    for (int i = 0; i < n - 1; i++){
        if (a[i] > a[i+1]) return false;
    }
    return true;
}
/*
     - Logic: Gán số lẻ min là - 1, check lần lượt trong mảng có phải là số lẻ không và có bé hơn số lẻ min không nếu thoả thì min là số vừa xét
*/
int cArray::TimLeMin(){
    int minLe = -1;
    bool coSoLe = false;
    for (int i = 0; i < n; i++){
        if (a[i] % 2 != 0){
            if (!coSoLe || a[i] < minLe){
                minLe = a[i];
                coSoLe = true;
            }
        }
    }
    return minLe;
}
/*
    - tương tự như hàm bài truoc
*/
bool laSNT(int n){
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) if(n % i == 0) return false;
    return true;
}
/*
    - Logic: Gán SNT max là - 1, check lần lượt trong mảng có snt không và có lớn hơn max không nếu thoả thì max là số vừa xét
*/
int cArray::TimSNTMax(){
    int maxSNT = -1;
    bool coSNT = false;
    for (int i = 0; i < n; i++) {
        if (laSNT(a[i])) {
            if (!coSNT || a[i] > maxSNT){
                maxSNT = a[i];
                coSNT = true;
            }
        }
    }
    return maxSNT;
}
/* - Logic: Selection Sort
*/
void cArray::SapXepTang(){
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) swap(a[i], a[j]);
        }
    }
}