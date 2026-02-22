// BOJ 1926번: 그림

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[502][502];
int vis[502][502];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int cnt = 0;
int ans = 0;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    queue<pair<int, int>> Q;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            if (board[x][y] == 1 && vis[x][y] == 0) {
                cnt++;
                vis[x][y] = 1;
                Q.push({x, y});

                int size = 0;

                while (!Q.empty()) {
                    pair<int, int> cur = Q.front();
                    Q.pop();
                    size++;

                    for (int i = 0; i < 4; i++) {
                        int nx = cur.X + dx[i];
                        int ny = cur.Y + dy[i];

                        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                        if (vis[nx][ny] > 0 || board[nx][ny] != 1) continue;

                        vis[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }

                if (ans < size) {
                    ans = size;
                }
            }
        }
    }

    cout << cnt << '\n';
    cout << ans << '\n';

    return 0;
}