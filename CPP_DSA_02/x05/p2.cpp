#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    stack<int> st;
    cin >> k;
    while (k--) {
        int v;
        cin >> v;
        if (v == 0) {
            if (!st.empty())
                st.pop();
        } else {
            st.push(v);
        }
    }

    int sum = 0;
    while (!st.empty()) {
        sum += st.top();
        st.pop();
    }

    cout << sum << '\n';

    return 0;
}