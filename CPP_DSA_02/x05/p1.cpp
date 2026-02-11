#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    stack<int> st;
    
    while (n--) {
        string str;
        cin >> str;
        if (str == "push") {
            int v;
            cin >> v;
            st.push(v);
        } else if (str == "pop") {
            if (!st.empty()) {
                cout << st.top() << '\n';
                st.pop();
            }
            else
                cout << -1 << '\n';
        } else if (str == "size") {
            cout << st.size() << '\n';
        } else if (str == "empty") {
            cout << (st.empty() ? 1 : 0) << '\n';
        } else if (str == "top") {
            cout << (st.empty() ? -1 : st.top()) << '\n';
        }
    }

    return 0;
}