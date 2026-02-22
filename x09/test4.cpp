// BOJ 4179번: 불!
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int R, C;

char board[1002][1002];
int distJ[1002][1002];
int distF[1002][1002];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int ans;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    queue<pair<int, int>> JQ;
    queue<pair<int, int>> FQ;

    cin >> R >> C;
    for (int x = 0; x < R; x++) {
        for (int y = 0; y < C; y++) {
            cin >> board[x][y];
            distJ[x][y] = -1;
            distF[x][y] = -1;
            if (board[x][y] == 'J') {
                JQ.push({x, y});
                distJ[x][y] = 0;
            } 
            if (board[x][y] == 'F') {
                FQ.push({x, y});
                distF[x][y] = 0;
            }
        }
    }

    while (!FQ.empty()) {
        pair<int, int> cur = FQ.front();
        FQ.pop();

        for (int k = 0; k < 4; k++) {
            int nx = cur.X + dx[k];
            int ny = cur.Y + dy[k];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (distF[nx][ny] > -1 || board[nx][ny] == '#') continue;

            distF[nx][ny] = distF[cur.X][cur.Y] + 1;
            FQ.push({nx, ny});
        }
    }

    while (!JQ.empty()) {
        pair<int, int> cur = JQ.front();
        JQ.pop();

        for (int k = 0; k < 4; k++) {
            int nx = cur.X + dx[k];
            int ny = cur.Y + dy[k];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
                cout << distJ[cur.X][cur.Y] + 1 << '\n';
                return 0;
            }
            if (distJ[nx][ny] > -1 || board[nx][ny] == '#') continue;
            if (distJ[cur.X][cur.Y] + 1 >= distF[nx][ny] && distF[nx][ny] != -1) continue;
            
            distJ[nx][ny] = distJ[cur.X][cur.Y] + 1;
            JQ.push({nx, ny});
        }
    }

    cout << "IMPOSSIBLE" << '\n';

    return 0;
}