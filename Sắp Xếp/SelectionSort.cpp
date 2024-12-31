#include <iostream> 
using namespace std;

void SapXepChon(int a[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int toithieu = i;
        for(int j = i + 1; j < n; j++) {
            if(a[j] < a[toithieu]) {
                toithieu = j; 
            }
        }
        int tmp = a[i]; 
        a[i] = a[toithieu]; 
        a[toithieu] = tmp; 
    }
}

int main() {
    int n; 
    cin >> n;
    int a[n];  
    for(int i =0; i < n; i++) {
        cin >> a[i]; 
    }

    SapXepChon(a , n); 
    for(int i = 0; i < n; i++) {
        cout << a[i]; 
    }
}