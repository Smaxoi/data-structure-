#include <iostream>
using namespace std;

void namesBubbleSort(char** names, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            char* p1 = names[j];
            while (*p1 != '\0') p1++;  
            if (p1 != names[j]) p1--;  // 防止空字串時指標往前跑出界

            char* p2 = names[j + 1];
            while (*p2 != '\0') p2++;
            if (p2 != names[j + 1]) p2--;  // 同樣檢查

            if (*p1 > *p2) {  // 依最後一個字元排序
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
            } else {
                cout << "[錯誤] 姓名長度超過 " << m
                     << "，請重新輸入第 " << (j + 1) << " 個姓名: ";
            }
        }
    }

    namesBubbleSort(names, n);

    cout << "排序結果:\n";
    for (int k = 0; k < n; k++) {
        cout << names[k] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        delete[] names[i];
    }
    delete[] names;
}