#include <bits/stdc++.h>
using namespace std;

int func(int N, int r, int c) {
    if (N == 0)
        return 0;

    int rect = 1 << (N - 1);

    // 재귀식
    if (rect > r && rect > c) return func(N - 1, r, c);
    if (rect > r && rect <= c) return rect * rect + func(N - 1, r, c - rect);
    if (rect <= r && rect > c) return 2 * rect * rect + func(N - 1, r - rect, c);
    if (rect <= r && rect <= c) return 3 * rect * rect + func(N - 1, r - rect, c - rect);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, r, c;
    cin >> N >> r >> c;

    cout << func(N, r, c) << '\n';

    return 0;
}