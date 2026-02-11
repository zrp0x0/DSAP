// BOJ 5397
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        string password;
        cin >> password;
        list<char> L;
        L.push_back('\0');
        list<char>::iterator it = L.begin();

        for (char c : password) {
            if (c == '<') {
                // 커서 왼쪽 이동
                if (it == L.begin()) {

                } else {
                    --it;
                }
                
            } else if (c == '>') {
                // 커서 오른쪽 이동
                ++it;
                if (it == L.end()) {
                    --it;
                }

            } else if (c == '-') {
                // 커서 왼쪽 글자 삭제
                if (it == L.begin()) {
                    
                } else {
                    it = L.erase(it);
                    it--;
                }

            } else {
                // 입력
                it++;
                it = L.insert(it, c);

            }
        }
        
        for (auto it = ++L.begin(); it != L.end(); ++it) {
            cout << *it;
        }
        cout << '\n';
    }

    return 0;
}
