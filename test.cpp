#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[502][502]; // 입력받는 맵
bool vis[502][502]; // 방문 여부 확인

int dx[] = {1, 0, -1, 0}; // 상하좌우
int dy[] = {0, 1, 0, -1}; // 상하좌우

int N = 7, M = 10; // 행, 열

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    queue<pair<int, int>> Q;

    vis[0][0] = 1; // 시작 지점을 방문 표시를 남김
    Q.push({0, 0}); // 시작 지점을 큐에 넣음

    while (!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++) {
            // 상하좌우 확인
            int nx = cur.X + dx[i]; 
            int ny = cur.Y + dy[i];

            // out of bound
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            // 이미 방문했거나 갈 수 없는 곳
            if (vis[nx][ny] || board[nx][ny] != 1) continue;

            // 방문하지않고 갈 수 있는 곳 처리
            vis[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }

    return 0;
}