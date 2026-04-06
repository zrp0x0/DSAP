// BOJ: 15683
#include <bits/stdc++.h>
using namespace std;

int N, M, ans = 1000;
char board[10][10];
char vis[10][10];
vector<pair<int, int>> cctv_list;

int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

// 범위 및 벽 체크
bool oob(int x, int y) {
    return (x < 0 || x >= N || y < 0 || y >= M) || (board[x][y] == '6');
}

// 사각지대 개수 계산
void breath() {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (vis[i][j] == '0') cnt++;
        }
    }
    ans = min(ans, cnt);
}

void watch(int x, int y, int dir) {
    dir %= 4;
    int nx = x;
    int ny = y;
    while (true) {
        nx += dx[dir];
        ny += dy[dir];
        if (oob(nx, ny)) break;
        if (vis[nx][ny] >= '1' && vis[nx][ny] <= '5') continue;
        vis[nx][ny] = '#';
    }
}

// 백트래킹
void solve(int idx) {
    if (idx == cctv_list.size()) {
        breath();
        return;
    }

    int x = cctv_list[idx].first;
    int y = cctv_list[idx].second;
    int type = board[x][y] - '0';

    char backup[10][10];

    for (int dir = 0; dir < 4; dir++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                backup[i][j] = vis[i][j];
            }
        }

        if (type == 1) {
            watch(x, y, dir);
        } else if (type == 2) {
            watch(x, y, dir);
            watch(x, y, dir+2);
        } else if (type == 3) {
            watch(x, y, dir);
            watch(x, y, dir + 1);
        } else if (type == 4) {
            watch(x, y, dir);
            watch(x, y, dir + 1);
            watch(x, y, dir + 2);
        } else if (type == 5) {
            watch(x, y, dir);
            watch(x, y, dir + 1);
            watch(x, y, dir + 2);
            watch(x, y, dir + 3);
        }

        solve(idx + 1);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                vis[i][j] = backup[i][j];
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            vis[i][j] = board[i][j];
            if (board[i][j] >= '1' && board[i][j] <= '5') {
                cctv_list.push_back({i, j});
            }
        }
    }
    solve(0);
    cout << ans << '\n';
    return 0;
}