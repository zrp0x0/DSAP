#include <bits/stdc++.h>
using namespace std;

string input;
string bomb;

deque<char> DQ;
stack<char> S;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> input;
    cin >> bomb;

    int be = bomb.length() - 1;
    char bb = bomb[be];

    // 핵심 로직
    for (int i = 0; i < input.length(); i++) {
        DQ.push_back(input[i]);

        int be = bomb.length() - 1;
        if (DQ.back() == bb) {
            while (!DQ.empty() && DQ.back() == bomb[be]) {
                S.push(DQ.back());
                DQ.pop_back();
                be--;
                if (be < 0)
                    break;
            }
            
            if (be < 0) {
                // 잘꺼내왔다
                while (!S.empty()) {
                    S.pop();
                }
            } else {
                // 못꺼내왔다
                while (!S.empty()) {
                    DQ.push_back(S.top());
                    S.pop();
                }
            }
        }
    }

    if (!DQ.empty()) {
        while (!DQ.empty()) {
            cout << DQ.front();
            DQ.pop_front();
        }
    cout << '\n';
    } else {
        cout << "FRULA" << '\n';
    }

    return 0;
}
