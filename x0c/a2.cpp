#include <bits/stdc++.h>
using namespace std;

int vis[16][16]; // bool로 하면 지워버림
int ans;
int N;

int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

void path(int x, int y, int val) {
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        while (nx >= 0 && nx < N && ny >= 0 && ny < N) {
            vis[nx][ny] += val;

            nx += dx[i];
            ny += dy[i];
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
            path(k, i, 1);

            func(k + 1);

            vis[k][i] += -1;
            path(k, i, -1);
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
