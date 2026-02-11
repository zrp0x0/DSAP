#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> st;
    st.push(5);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);

    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();

    // cout << "RunTime Error before top" << '\n';
    // cout << st.top() << '\n';

    cout << "RunTime Error before pop" << '\n';
    st.pop();

    return 0;
}