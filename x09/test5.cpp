// BOJ 1697번: 숨박꼭질
#include <bits/stdc++.h>
using namespace std;

int N, K;

int vis[100002];

int dx[] = {1, -1, 2};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 100002; i++) {
        vis[i] = -1;
    }

    queue<int> Q;

    cin >> N >> K;

    Q.push(N);
    vis[N] = 0;

    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();

        for (int i = 0; i < 3; i++) {

            int nx = 0;
            if (i == 2) {
                nx = cur * dx[i];
            } else {
                nx = cur + dx[i];
            }

            if (nx < 0 || nx > 100000) continue;
            if (vis[nx] > -1) continue;

            Q.push(nx);
            vis[nx] = vis[cur] + 1;
        }
    }

    cout << vis[K] << '\n';

    return 0;
}