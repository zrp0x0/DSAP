// BOJ 2206번: 벽 부수고 이동하기
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N, M;

char board[1002][1002];
int dist[1002][1002][2];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            board[i][j] = board[i][j] - '0';
            dist[i][j][0] = dist[i][j][1] = -1;
        }
    }

    queue<tuple<int, int, int>> Q;
    dist[0][0][0] = 1;
    dist[0][0][1] = 1;
    Q.push({0, 0, 0});

    while (!Q.empty()) {
        tuple<int, int, int> cur = Q.front();
        Q.pop();

        if (get<0>(cur) == N - 1 && get<1>(cur) == M - 1) {
            cout << dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] << '\n';
            return 0;
        }

        for (int k = 0; k < 4; k++) {
            int nx = get<0>(cur) + dx[k];
            int ny = get<1>(cur) + dy[k];
            int brk = get<2>(cur);

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (board[nx][ny] == 0 && dist[nx][ny][brk] == -1) {
                dist[nx][ny][brk] = dist[get<0>(cur)][get<1>(cur)][brk] + 1;
                Q.push({nx, ny, brk});
            }

            if (!brk && board[nx][ny] == 1 && dist[nx][ny][1] == -1) {
                dist[nx][ny][1] = dist[get<0>(cur)][get<1>(cur)][brk] + 1;
                Q.push({nx, ny, 1});
            }
        }
    }

    cout << -1 << '\n';

    return 0;
}