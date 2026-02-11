#include <bits/stdc++.h>
using namespace std;

int room[13];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, sex, grade, ans = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> sex >> grade;
        room[sex * 6 + grade]++;
    }

    for (int i = 1; i < 13; i++) {
        ans += room[i] / k;
        if (room[i] % k != 0) {
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}

// 이차원 배열로 하는 것도 괜찮다