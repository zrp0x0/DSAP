#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<int> st;
    vector<char> stv;
    
    int n;
    cin >> n;
    
    int i = 1;
    while (n--) {
        int v;
        cin >> v;

        // 작으면 계속해서 넣기
        while (v >= i) {
            st.push(i++);
            stv.push_back('+');
        }

        // 크면 검사해야함 -> 바로 이전만 보고 가능성을 판단할 수 있음 -> top()
        if (st.top() == v) {
            st.pop();
            stv.push_back('-');
        } else {
            cout << "NO" << '\n';
            return 0;         
        }
    }

    for (vector<char>::iterator it = stv.begin(); it != stv.end(); ++it) {
        cout << *it << '\n';
    }

    return 0;
}