#include <bits/stdc++.h>
using namespace std;

int board[6570][6570];

void func(int N, int r, int c) {
    if (N == 1) {
        board[r][c] = 1;
        return;
    }

    int nxtN = N / 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) {

            } else {
                func(nxtN, r + i * nxtN, c + j * nxtN);
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    func(N, 0, 0);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j]) {
                cout << '*';
            } else {
                cout << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}