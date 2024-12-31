#include <iostream> 
using namespace std; 

// Hàm sắp xếp nổi bọt (Bubble Sort)
void BubbleSort(int a[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp; 
            }
        }
    }
}

int main() {
    int n; 
    cin >> n;
    int a[n]; 
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    BubbleSort(a, n);
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
