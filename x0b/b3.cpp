#include <bits/stdc++.h>
using namespace std;

int board[130][130];
int cnt[2];

bool check(int N, int r, int c) {
    for (int i = r; i < r + N; i++) {
        for (int j = c; j < c + N; j++) {
            if (board[r][c] != board[i][j])
                return false;
        }
    }
    return true;
}

void func(int N, int r, int c) {
    if (check(N, r, c)) {
        cnt[board[r][c]]++;
        return;
    }

    int nxtN = N / 2;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            func(nxtN, r + i * nxtN, c + j * nxtN);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    func(N, 0, 0);

    cout << cnt[0] << '\n';
    cout << cnt[1] << '\n';

    return 0;
}