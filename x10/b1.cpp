#include <bits/stdc++.h>
using namespace std;

int T, N;
int D[41][2];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;

    D[0][0] = 1;
    D[0][1] = 0;
    D[1][0] = 0;
    D[1][1] = 1;

    for (int i = 2; i <= 40; i++) {
        D[i][0] = D[i-1][0] + D[i-2][0];
        D[i][1] = D[i-1][1] + D[i-2][1];
    }

    for (int i = 0; i < T; i++) {
        cin >> N;
        cout << D[N][0] << ' ' <<  D[N][1] << '\n';
    }
    return 0;
}