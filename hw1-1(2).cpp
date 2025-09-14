#include <iostream>

using namespace std;

void namesBubbleSort(char** names, int n) {
   for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1 ; j++) {
        
        char* p1 = names[j];
        while (*p1 != '\0') {
            p1++;
        }
        p1--;  

        char* p2 = names[j + 1];
        while (*p2 != '\0') {
            p2++;
        }
        p2--; 

        if (*p1 > *p2) {
            char* temp = names[j];
            names[j] = names[j + 1];
            names[j + 1] = temp;
        }
    }
}
}


int main() {
    int n, m;
    cout << "輸入學生數量:"; 
    cin >> n;
    cout << "輸入姓名姓名長度:";
    cin >> m;
    
    char** names = new char*[n];
    for (int i = 0; i < n; i++) {
        names[i] = new char[m + 1];
    }
    
     cout << "請輸入 " << n << " 個姓名 (長度不能超過 " << m << "):\n";

    for (int j = 0; j < n; j++) {
        while (true) {
            cin >> names[j];
            int len = 0;
            while (names[j][len] != '\0') len++;

            if (len <= m) {
                break; 
                cout << "[錯誤] 姓名長度超過 " << m 
                     << "，請重新輸入第 " << (j + 1) << " 個姓名: ";
                cin.clear();
            }
        }
    }

    
    namesBubbleSort(names, n);
    
    for (int k = 0; k < n; k++) {
        cout << names[k] <<" ";
    }
    
}
