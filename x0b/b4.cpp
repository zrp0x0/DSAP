#include <bits/stdc++.h>
using namespace std;

char board[64][64];

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
        cout << board[r][c];
        return;
    }

    cout << '(';
    int nxtN = N / 2;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            func(nxtN, r + i * nxtN, c + j * nxtN);
        }
    }
    cout << ')';
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

    return 0;
}
