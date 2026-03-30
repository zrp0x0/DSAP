// BOJ: 10808
#include <bits/stdc++.h>
using namespace std;

int A, B, C;
string str;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> str;
    for (char i = 'a'; i < 'z'; i++) {
        int cnt = 0;
        for (char c : str) {
            if (i == c) cnt++;
        }
        cout << cnt << ' ';
    }
    cout << '\n';
    return 0;
}

/*
1. 문자열 입력 받기
2. 문자열 마다 각 알파벳이 뭐가 있는지 확인하기 => O(N * K)
*/