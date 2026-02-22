// BOJ 2178번: 미로 탐색

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

#define X first
#define Y second

int board[102][102];
int dist[102][102];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    for (int x = 0; x < N; x++) {
        string str;
        cin >> str;
        for (int y = 0; y < M; y++) {
            board[x][y] = str[y] - '0';
        }
    }

    queue<pair<int, int>> Q;
    Q.push({0, 0});
    dist[0][0] = 1;

    while (!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = cur.X + dx[k];
            int ny = cur.Y + dy[k];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (dist[nx][ny] > 0 || board[nx][ny] == 0) continue;

            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }

    cout << dist[N - 1][M - 1] << '\n';

    return 0;
}