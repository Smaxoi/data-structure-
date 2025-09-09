#include <iostream>
#include <string>
#include <cstring>  // strlen, strcpy
using namespace std;

void printspace(string* temp, int x, int mids) {
    for (int i = 0; i < x; i++) {
        int pos = 0;
        while (pos < (int)temp[i].size() && temp[i][pos] != ' ') {
            pos++;
        }
        for (int k = 0; k < mids - pos; k++) {
            cout << ' ';
        }
        cout << temp[i] << endl;
    }
}


int main() {
    int x;
    cout << "請輸入學生人數: ";
    cin >> x;
    string* temp = new string[x];
    int maxLen = 0;
    int mids = 0;

    cout << "請輸入 " << x << " 個英文全名:" << endl;
    cin.ignore(); // 清掉 cin 的換行符
    for (int i = 0; i < x; i++) {
        getline(cin, temp[i]);
        int j = 0;
        int k = 0;
        while (j < (int)temp[i].size() && temp[i][j] != '\0') {
            k++;
        }
        if (k > maxLen) {
            maxLen = k;
        }
        while (j < (int)temp[i].size() && temp[i][j] != ' ') {
            j++;
        }
        if (j > mids) {
            mids = j;
        }
    }


    char** names = new char*[x];
    for (int i = 0; i < x; i++) {
        names[i] = new char[maxLen + 1];
        strcpy(names[i], temp[i].c_str());
    }
    

    printspace(temp, x, mids);

    for (int i = 0; i < x; i++) {
        delete[] names[i];
    }
    delete[] names;
    delete[] temp;

    return 0;
}
