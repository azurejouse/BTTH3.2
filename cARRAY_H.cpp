#include "cARRAY_H.h"
cArray::cArray(int size) : n(size) {
    a = new int[n];
    backup = new int[n];
}
cArray::~cArray() {
    delete[] a;
    delete[] backup;
}
// Logic: Dùng vòng lặp for để nhập n phần tử và sao lưu vào backup
void cArray::Nhap() {
    cout << "Nhap n: "; cin >> n;
    delete[] a; delete[] backup;
    a = new int[n];
    backup = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = "; cin >> a[i];
        backup[i] = a[i];
    }
}
// Logic: Duyệt for từ đầu đến cuối để in mảng
void cArray::Xuat() {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
// Logic: Duyệt for để khôi phục mảng gốc từ backup
void cArray::Reset() {
    for (int i = 0; i < n; i++) {
        a[i] = backup[i];
    }
}
// Logic: Duyệt for, nếu a[i] == x thì tăng biến đếm
int cArray::DemX(int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) count++;
    }
    return count;
}
// Logic: Duyệt for để so sánh cặp phần tử kề nhau
bool cArray::KiemTraTangDan() {
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) return false;
    }
    return true;
}
// Logic: Duyệt for để tìm số lẻ nhỏ nhất
int cArray::TimLeMin() {
    int minLe = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            if (minLe == -1 || a[i] < minLe) minLe = a[i];
        }
    }
    return minLe;
}
// Hàm bổ trợ kiểm tra số nguyên tố
bool cArray::laSNT(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}
// Logic: Duyệt for để tìm số nguyên tố lớn nhất
int cArray::TimSNTMax() {
    int maxSNT = -1;
    for (int i = 0; i < n; i++) {
        if (laSNT(a[i])) {
            if (maxSNT == -1 || a[i] > maxSNT) maxSNT = a[i];
        }
    }
    return maxSNT;
}
// Logic: Duyệt for để tìm giá trị lớn nhất trong mảng
int cArray::getMax() {
    int mx = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > mx) mx = a[i];
    }
    return mx;
}
// 1. Insertion Sort: Dùng for lồng vòng while để chèn phần tử
void cArray::InsertionSort() {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        for (; j >= 0 && a[j] > key; j--) {
            a[j + 1] = a[j];
        }
        a[j + 1] = key;
    }
}
// 2. Merge Sort: Chia để trị và dùng for để trộn mảng
void cArray::merge(int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = new int[n1], *R = new int[n2];
    for (int i = 0; i < n1; i++) L[i] = a[l + i];
    for (int j = 0; j < n2; j++) R[j] = a[m + 1 + j];
    
    int i = 0, j = 0, k = l;
    for (; i < n1 && j < n2; k++) {
        if (L[i] <= R[j]) a[k] = L[i++];
        else a[k] = R[j++];
    }
    for (; i < n1; i++, k++) a[k] = L[i];
    for (; j < n2; j++, k++) a[k] = R[j];
    delete[] L; delete[] R;
}
void cArray::MergeSort(int l, int r){
    if (l < r) {
        int m = l + (r - l) / 2;
        MergeSort(l, m);
        MergeSort(m + 1, r);
        merge(l, m, r);
    }
}
// 3. Quick Sort: Dùng vòng lặp while để phân đoạn mảng
void cArray::QuickSort(int l, int r) {
    int i = l, j = r;
    int pivot = a[l + (r - l) / 2];
    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++; j--;
        }
    }
    if (l < j) QuickSort(l, j);
    if (i < r) QuickSort(i, r);
}
// 4. Heap Sort: Dùng for để xây dựng cấu trúc Heap
void cArray::heapify(int n_heap, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n_heap && a[left] > a[largest]) largest = left;
    if (right < n_heap && a[right] > a[largest]) largest = right;
    if (largest != i) {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        heapify(n_heap, largest);
    }
}
void cArray::HeapSort() {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(n, i);
    for (int i = n - 1; i > 0; i--) {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(i, 0);
    }
}
// 5. Counting Sort: Dùng for để đếm và xếp lại mảng
void cArray::CountingSort(){
    int mx = getMax();
    int *count = new int[mx + 1];
    for (int i = 0; i <= mx; i++) count[i] = 0;
    for (int i = 0; i < n; i++) count[a[i]]++;
    for (int i = 1; i <= mx; i++) count[i] += count[i - 1];   
    int *output = new int[n];
    for (int i = n - 1; i >= 0; i--){
        output[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }
    for (int i = 0; i < n; i++) a[i] = output[i];
    delete[] count; delete[] output;
}
// 6. Radix Sort: Dùng vòng for để sắp xếp theo từng chữ số
void cArray::RadixSort() {
    int m = getMax();
    for (int exp = 1; m / exp > 0; exp *= 10){
        int output[100];
        int count[10] = {0};
        for (int i = 0; i < n; i++) count[(a[i] / exp) % 10]++;
        for (int i = 1; i < 10; i++) count[i] += count[i - 1];
        for (int i = n - 1; i >= 0; i--) {
            output[count[(a[i] / exp) % 10] - 1] = a[i];
            count[(a[i] / exp) % 10]--;
        }
        for (int i = 0; i < n; i++) a[i] = output[i];
    }
}
