// BOJ 1158
#include <iostream>
#include <list>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int count;
    list<int> L;
    count = n;
    while (count) {
        L.push_front(count--);
    }

    list<int>::iterator it = L.begin();
    cout << '<';
    while (n--) {
        for (int i = 0; i < k - 1; i++) {
            it++;
            if (it == L.end()) {
                it = L.begin();
            }
        }
        cout << *it;
        it = L.erase(it);
        if (it == L.end()) 
            it = L.begin();
        if (n != 0) {
            cout << ", ";
        }
    }
    cout << '>' << '\n';

    return 0;
}

// Queue를 사용한 풀이도 있다
// 내가 구현한 건 연결 리스틀 활용한 풀이
// 근데 이런 순환 문제면 Stack / Queue / Deque를 해보는 것도 좋을듯