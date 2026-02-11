#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<int> st1;
    stack<pair<int, int>> st2;
    stack<int> st3;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        st1.push(v);
    }

    st2.push({1000001, -1});
    for (int i = 0; i < n; i++) {

        while (st2.top().first <= st1.top()) {
            st2.pop();
        }
        st3.push(st2.top().second);
        st2.push({st1.top(), st1.top()});
        
        st1.pop();
    }

    while (n--) {
        cout << st3.top() << ' ';
        st3.pop();
    }

    return 0;
}