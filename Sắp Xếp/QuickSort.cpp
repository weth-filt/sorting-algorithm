#include <iostream>
using namespace std;

// Hàm đổi chỗ hai phần tử
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Hàm phân hoạch (Partition)
int partition(int a[], int start, int end) {
    int chot = a[end]; 
    int i = start - 1; 

    for (int j = start; j < end; j++) {
        if (a[j] < chot) { 
            i++; 
            swap(a[i], a[j]); 
        }
    }
    swap(a[i + 1], a[end]); 
    return i + 1; 
}

// Hàm sắp xếp nhanh (Quick Sort)
void quickSort(int a[], int start, int end) {
    if (start < end) {
        int pi = partition(a, start, end);
        quickSort(a, start, pi - 1); 
        quickSort(a, pi + 1, end); 
    }
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    quickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
