#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000005;
int dat[MAX]; // <bits/stdc++.h>에 std::data랑 충돌이 일어날 수 있음
int pos = 0;

void push(int x) {
    dat[pos] = x;
    pos++;
}

void pop() {
    if (pos > 0)
        pos--;
}

int top() {
    if (pos > 0)
        return dat[pos - 1];
    return -1;
}

void test() {
push(5); push(4); push(3);
    cout << top() << '\n'; // 3
    pop(); pop();
    cout << top() << '\n'; // 5
    push(10); push(12);
    cout << top() << '\n'; // 12
    pop();
    cout << top() << '\n'; // 10
}

int main() {
    test();
    return 0;
}