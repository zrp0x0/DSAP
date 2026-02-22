// BOJ 7576번: 토마토

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N, M;
int ans;

int board[1002][1002];
int dist[1002][1002];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N;

    queue<pair<int, int>> Q;

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            cin >> board[x][y];
            dist[x][y] = -1;
            if (board[x][y] == 1) {
                Q.push({x, y});
                dist[x][y] = 0;
            }
        }
    }

    while (!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = cur.X + dx[k];
            int ny = cur.Y + dy[k];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (dist[nx][ny] > -1 || board[nx][ny] == -1) continue;

            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            ans = dist[nx][ny];
            board[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            if (board[x][y] == 0) {
                cout << -1 << '\n';
                return 0;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}