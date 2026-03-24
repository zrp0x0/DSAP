#include <bits/stdc++.h>
using namespace std;

int T; // 도착 계단 위치 / 1 <= T <= 300
int S[305];
int D[305][3];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> S[i];
    }

    if (T == 1) {
        cout << S[1] << '\n';
        return 0;
    }
    
    D[1][1] = S[1];
    D[1][2] = 0;
    D[2][1] = S[2];
    D[2][2] = S[1] + S[2];

    for (int i = 3; i <= T; i++) {
        D[i][1] = max(D[i-2][1], D[i-2][2]) + S[i];
        D[i][2] = D[i-1][1] + S[i];
    }

    cout << max(D[T][1], D[T][2]) << '\n';

    return 0;
}