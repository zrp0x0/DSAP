// BOJ 2206번: 벽 부수고 이동하기
#include <bits/stdc++.h>
using namespace std;

char board[1002][1002];
int vis[1002][1002][2];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    queue<tuple<int, int, int>> Q;
    Q.push({0, 0, 0});
    vis[0][0][0] = 1;

    while (!Q.empty()) {
        tuple<int, int, int> cur = Q.front();
        Q.pop();

        if (get<0>(cur) == N - 1 && get<1>(cur) == M - 1) {
            cout << vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] << '\n';
            // for (int x = 0; x < N; x++) {
            //     for (int y = 0; y < M; y++) {
            //         cout << vis[x][y][get<2>(cur)] << ' ';
            //     }
            //     cout << '\n';
            // }
            return 0;
        }

        for (int k = 0; k < 4; k++) {
            int nx = get<0>(cur) + dx[k];
            int ny = get<1>(cur) + dy[k];
            int broken = get<2>(cur);

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            
            if (board[nx][ny] == '1' && broken == 0 && vis[nx][ny][1] == 0) { // 벽에 막혀있고, 아직 한 번도 부수지 않았다면
                Q.push({nx, ny, 1});
                vis[nx][ny][1] = vis[get<0>(cur)][get<1>(cur)][broken] + 1;
                continue;
            } else if (board[nx][ny] == '1' && broken == 1) {
                continue;
            }

            if (board[nx][ny] == '0' && vis[nx][ny][broken] == 0) { 
                Q.push({nx, ny, broken});
                vis[nx][ny][broken] = vis[get<0>(cur)][get<1>(cur)][broken] + 1;
            }
        }
    }

    cout << -1 << '\n';

    return 0;
}