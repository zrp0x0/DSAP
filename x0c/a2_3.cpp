#include <bits/stdc++.h>
using namespace std;

int N;
int ans;
int vis[15][15];

void atk(int x, int y, int val) {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // y 좌표
            if (y == j)
                vis[i][j] += val;

            // 대각선 1
            if ((x + y) == (i + j))
                vis[i][j] += val;

            // 대각선 2
            if ((x - y) == (i - j))
                vis[i][j] += val;
        }
    }
}

void func(int k) {
    if (k == N) {
        ans++;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!vis[k][i]) {
            vis[k][i] += 1;
            atk(k, i, 1);

            func(k + 1);

            vis[k][i] += -1;
            atk(k, i, -1);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    func(0);
    cout << ans << '\n';

    return 0;
}
// 좀만 더 고민해보자