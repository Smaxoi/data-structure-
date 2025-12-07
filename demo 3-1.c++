#include <iostream>
using namespace std;

struct Node {
    int coef;
    int exp;
    Node* next;
    Node(int c = 0, int e = 0) : coef(c), exp(e), next(nullptr) {}//建構子初始化 (dummy header萬歲)
};

Node* newPoly() {
    Node* h = new Node();
    h -> next = h;
    return h;
}

void insertSort(Node* head, int c, int e) {
    if (c == 0) return;
    
    Node* prev = head;
    Node* curr = head -> next;
    
    while(curr != head && curr -> exp > e) { //找到次方相同的term 如果沒有的話prev會停在exp比e大的curr會停在小於等於e的
        prev = curr;
        curr = curr -> next;
    }
    
    if (curr != head && curr -> exp == e) { //如果(curr -> exp = e)相同次方相加係數
        curr -> coef += c;
        
        if (curr -> coef == 0) {
            prev -> next = curr -> next; //加完變0
            delete curr;
        }
        return;
    }
    //都沒有符合的話 (prev -> exp > input e > curr -> exp)
    Node* t = new Node(c,e);
    t -> next = curr;
    prev -> next = t;
    //創一個新的Node插到prev和curr之間
} 

Node* readPoly() {
    int m; //輸入有多少個term
    cin >> m;
    Node* H = newPoly();
    while(m--){
        int c, e;
        cin >> c >> e;
        insertSort(H, c, e); //用insertSort去創立
    }
    return H;
}

void printPoly(Node* H) {
    Node* p = H -> next;
    if (p == H) {
        cout << 0;
        return;
    }
    bool first = true;
    while (p != H) {
        if (!first && p -> coef > 0) {
            cout << "+";
        }
        cout << p -> coef << "x^" << p -> exp;
        first = false;
        p = p -> next;
    }
}

Node* polyAdd(Node* A, Node* B) {
    Node* C = newPoly();
    Node* pa = A -> next;
    Node* pb = B -> next;
    
    while (pa != A && pb != B) {
        if (pa -> exp > pb -> exp) { // Ａ > B
            insertSort(C, pa -> coef, pa -> exp);
            pa = pa -> next;
        }
        else if (pa -> exp < pb -> exp) { // A < B
            insertSort(C, pb -> coef, pb -> exp);
            pb = pb -> next;
        }
        else { // A = B
            insertSort(C, pa -> coef + pb -> coef, pa -> exp);
            pa = pa -> next;
            pb = pb -> next;
        }
    }
    //上面A或者B一邊會先跑到head的位置 剩下另一邊直接丟進去
    while(pa != A){
        insertSort(C, pa -> coef, pa -> exp);
        pa = pa -> next;
    }
    while(pb != B){
        insertSort(C, pb -> coef, pb -> exp);
        pb = pb -> next;
    }
    return C;
}

Node* polyMul(Node* A, Node* B) {
    Node* C = newPoly();
    for(Node* pa = A -> next; pa != A; pa = pa -> next) {
        for(Node* pb = B -> next; pb != B; pb = pb -> next) {
            insertSort(C, pa -> coef * pb -> coef, pa -> exp + pb -> exp);
        }
    }
    return C;
}


int main()
{
    // 輸入格式：
    // m
    // c1 e1
    // c2 e2
    // ...
    // n
    // d1 f1
    // d2 f2
    // ...
    Node* A = readPoly();
    Node* B = readPoly();

    Node* C = polyMul(A, B);
    printPoly(C);
    return 0;

    return 0;
}
