#include <bits/stdc++.h>
using namespace std;

int func(int N, int r, int c) {

    int ans = 0;
    int rect = 1 << (N - 1);

    while (rect > 0) {
        int area = rect * rect;

        if (r < rect && c < rect) {

        } else if (r < rect && c >= rect) {
            ans += area;
            c -= rect;
        } else if (r >= rect && c < rect) {
            ans += 2 * area;
            r -= rect;
        } else {
            ans += 3 * area;
            r -= rect;
            c -= rect;
        }

        rect /= 2;
    }

    return ans;  
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, r, c;
    cin >> N >> r >> c;
    cout << func(N, r, c) << '\n';

    return 0;
}