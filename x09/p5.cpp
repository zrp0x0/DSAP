// BOJ 5427번: 불
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

char board[1001][1001];

int distF[1001][1001];
int distJ[1001][1001];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> M >> N;

        queue<pair<int, int>> QF;
        queue<pair<int, int>> QJ;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                board[i][j] = 0;
                distF[i][j] = 0;
                distJ[i][j] = 0;
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> board[i][j];
                distF[i][j] = -1;
                distJ[i][j] = -1;
                if (board[i][j] == '*') {
                    QF.push({i, j});
                    distF[i][j] = 0;
                }

                if (board[i][j] == '@') {
                    QJ.push({i, j});
                    distJ[i][j] = 0;
                }
            }
        }

        while (!QF.empty()) {
            pair<int, int> cur = QF.front();
            QF.pop();

            for (int k = 0; k < 4; k++) {
                int nx = cur.X + dx[k];
                int ny = cur.Y + dy[k];

                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if (distF[nx][ny] > -1 || board[nx][ny] == '#') continue;

                QF.push({nx, ny});
                distF[nx][ny] = distF[cur.X][cur.Y] + 1;
            }
        }

        bool flag = false;
        while (!QJ.empty() && (!flag)) {
            pair<int, int> cur = QJ.front();
            QJ.pop();

            for (int k = 0; k < 4; k++) {
                int nx = cur.X + dx[k];
                int ny = cur.Y + dy[k];

                if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
                    cout << distJ[cur.X][cur.Y] + 1 << '\n';
                    flag = true;
                    break;
                }
                if (distJ[nx][ny] > -1 || board[nx][ny] == '#') continue;
                if (distF[nx][ny] <= distJ[cur.X][cur.Y] + 1 && distF[nx][ny] != -1) continue;

                QJ.push({nx, ny});
                distJ[nx][ny] = distJ[cur.X][cur.Y] + 1;
            }
        }

        if (!flag) {
            cout << "IMPOSSIBLE" << '\n';
        }
    }

    return 0;
}