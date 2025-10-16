#include <iostream>     // 提供輸入輸出功能
#include <stdexcept>    // 提供例外類別 (out_of_range, invalid_argument)
using namespace std;

class CppArray {
public:
    // (a) 建構子：建立陣列並設定初值
    explicit CppArray(int size = 10, float initValue = 0.0f) {
        //if (size <= 0) throw invalid_argument("size must be > 0");
        size_ = size;
        data_ = new float[size_];           // 配置動態記憶體
        for (int i = 0; i < size_; ++i)
            data_[i] = initValue;           // 初始化每個元素
    }

    // (b) 複製建構子：用舊陣列建立新陣列
    CppArray(const CppArray& other) {
        size_ = other.size_;
        data_ = new float[size_];
        for (int i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];      // 深拷貝資料
        }
    }

    // (c) 指派運算子：讓已存在的陣列可用 = 被覆蓋
    CppArray& operator=(const CppArray& other) {
        if (this != &other) {               // 防止自我指派 (a = a)
            delete[] data_;                 // 先刪舊記憶體
            size_ = other.size_;
            data_ = new float[size_];       // 重新分配空間
            for (int i = 0; i < size_; ++i)
                data_[i] = other.data_[i];  // 複製每個值
        }
        return *this;                       // 回傳自己 (支援 a=b=c)
    }

    // (d) 解構子：釋放動態記憶體
    ~CppArray() {
        delete[] data_;
    }

    // (e) 下標運算子：用來存取元素，並檢查範圍
    float& operator[](int i) {
        if (i < 0 || i >= size_)
            throw out_of_range("index out of range");
        return data_[i];
    }

    // (f) 取得陣列大小
    int GetSize() const {
        return size_;
    }

    // (g) 輸入 / 輸出運算子（使用 friend）
    friend istream& operator>>(istream& in, CppArray& a) {
        for (int i = 0; i < a.size_; ++i)
            in >> a.data_[i];               // 逐一讀入元素
        return in;
    }

    friend ostream& operator<<(ostream& out, const CppArray& a) {
        for (int i = 0; i < a.size_; ++i) {
            if (i > 0) out << " ";          // 元素間以空白分隔
            out << a.data_[i];
        }
        return out;
    }

private:
    int size_;       // 陣列大小
    float* data_;    // 指向動態配置的記憶體
};

// ==============================
// 主程式示範
// ==============================
int main() {
    CppArray a(3, 0.0f);         // 建立 3 個元素、初值 0
    cout << "請輸入 3 個浮點數：" << endl;
    cin >> a;                    // 用 >> 讀入三個 float
    cout << "陣列 a 的內容為：" << a << endl;

    CppArray b = a;              // 複製建構子
    CppArray c(3, 5.0f);         // 另一個陣列
    c = a;                       // 指派運算子

    cout << "陣列 b：" << b << endl;
    cout << "陣列 c：" << c << endl;
    cout << "陣列大小：" << a.GetSize() << endl;

    // 試試範圍檢查
    // cout << a[5] << endl;     // 若取消註解，會丟出 out_of_range 錯誤

    return 0;
}
