#include <iostream> 
#include <conio.h>
using namespace std; 

// Selection Sort ( sắp xếp chọn )
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

//Bubble Sort ( sắp xếp nổi bọt )
void SapXepNoiBot(int a[], int n) {
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

//Insertion Sort ( sắp xếp chèn )
void SapXepChen(int a[], int n) {
    for(int i = 1; i < n; i++) {
        int chiso = i - 1, x = a[i]; 
        while(chiso >= 0 && a[chiso] >= x) {
            a[chiso + 1] = a[chiso]; 
            --chiso; 
        } 
        a[chiso + 1] = x; 
    }
}

// Merge Sort ( sắp xếp trộn )
void merge(int a[], int r, int l, int m) {
    int n1 = m - l + 1, n2 = r - m; 
    int x[n1], y[n2];
    for(int i = l; i <= m; i++) {
        x[i - l] = a[i]; 
    } 
    for(int i = m + 1; i <= r; i++) {
        y[i - m - 1] = a[i]; 
    }
    int i = 0, j = 0; 
    while(i < n1 && j < n2) {
        if(x[i] <= y[j]) {
            a[l] = x[i]; 
            ++l;
            ++i;
        } else {
            a[l] = y[j]; 
            ++l; 
            ++j; 
        }
    }
    while(i < n1) {
        a[l] = x[i]; 
        ++l; 
        ++i; 
    }   
    while(j < n2) {
        a[l] = y[j]; 
        ++l; 
        ++j;
    }
}

void SapXepTron(int a[], int l, int r) {
    if(l < r) {
        int m = (l + r) / 2; 
        SapXepTron(a, l, m); 
        SapXepTron(a, m + 1, r);
        merge(a, r, l, m); 
    }
}

int main() {
    int luachon, n;
    int a1[100], a2[100], a3[100], a4[100]; 

    do {
        cout << "1. Sap xep chon (Selection Sort) " << endl;
        cout << "2. Sap xep noi bot (Bubble Sort) " << endl;
        cout << "3. Sap xep chen (Insertion Sort) " << endl;
        cout << "4. Sap xep tron (Merge Sort) " << endl;
        cout << "Chon phep tinh muon tinh (ESC de thoat): ";
        luachon = getch();
        if (luachon >= '1' && luachon <= '4') {
            system("cls");
            switch(luachon - '0') {
                case 1:
                    cin >> n;
                    for(int i = 0; i < n; i++) {
                        cin >> a1[i]; 
                    }
                    SapXepChon(a1 , n); 
                    for(int i = 0; i < n; i++) {
                        cout << a1[i] << " "; 
                    }
                    break;
                case 2:
                    cin >> n;
                    for(int i = 0; i < n; i++) {
                        cin >> a2[i]; 
                    }
                    SapXepNoiBot(a2 , n); 
                    for(int i = 0; i < n; i++) {
                        cout << a2[i] << " "; 
                    }
                    break;
                case 3:
                    cin >> n;
                    for(int i = 0; i < n; i++) {
                        cin >> a3[i]; 
                    }
                    SapXepChen(a3 , n); 
                    for(int i = 0; i < n; i++) {
                        cout << a3[i] << " "; 
                    }
                    break;
                case 4:
                    cin >> n;
                    for(int i = 0; i < n; i++) {
                        cin >> a4[i]; 
                    }
                    SapXepTron(a4 , 0, n - 1); 
                    for(int i = 0; i < n; i++) {
                        cout << a4[i] << " "; 
                    }
                    break;
            }
            cout << "\nNhan Enter de quay lai menu. " << endl;
            getch();
            system("cls");
        } else if(luachon != 27) {
            cout << "Lua chon khong hop le. ";
            getch();
            system("cls");
        }
    } while (luachon != 27);
    return 0;
}
