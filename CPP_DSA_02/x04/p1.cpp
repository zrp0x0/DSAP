// BOJ 1406
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    string str;
    cin >> str;
    list<char> str_list;
    str_list.push_back('0');
    for (char c : str) {
        str_list.push_back(c);
    }

    list<char>::iterator it = --str_list.end();
    // [begin] [] [] [] [end]

    cin >> m;
    for (int i = 0; i < m; i++) {
        char command;
        cin >> command;
        if (command == 'L') {
            // 왼쪽으로 한 칸 옮김
            // 맨 앞이면 무시됨
            // a - b - c - d - end    
            if (it == str_list.begin()) {

            } else {
                --it;
            }

        } else if (command == 'D') {
            // 오른쪽으로 한 칸 옮김
            // 맨 뒤면 무시됨
            if (it == --str_list.end()) {

            } else {
                it++;
            }

        } else if (command == 'B') {
            // 커서 왼쪽에 있는 문자를 삭제함
            // 맨 앞이면 무시됨
            // 그대로 있어야함
            if (it == str_list.begin()) {

            } else {
                it = str_list.erase(it);
                --it;
            }

        } else if (command == 'P') {
            char what;
            cin >> what;
            it++;
            it = str_list.insert(it, what);
        }
    }

    list<char>::iterator out = ++str_list.begin();
    for (; out !=  str_list.end(); ++out) {
        cout << *out;
    }
    cout << '\n';

    return 0;
}
