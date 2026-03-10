#include <bits/stdc++.h>
using namespace std;

string input;
string bomb;

deque<char> DQ;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> input;
    cin >> bomb;

    // 핵심 로직
    for (int i = 0; i < input.length(); i++) {
        DQ.push_back(input[i]);
        
    }

    while (!DQ.empty()) {
        cout << DQ.front();
        DQ.pop_front();
    }

    return 0;
}
