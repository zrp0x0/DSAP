#include <bits/stdc++.h>
using namespace std;

int X;
int D[1000005];
int P[1000005];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> X;
    D[1] = 0;
    P[1] = 0;

    for (int i = 2; i <= X; i++) {
        D[i] = D[i-1] + 1;
        P[i] = i-1;

        if (i % 2 == 0 && D[i] > D[i/2] + 1) {
            D[i] = D[i/2] + 1;
            P[i] = i/2;
        }

        if (i % 3 == 0 && D[i] > D[i/3] + 1) {
            D[i] = D[i/3] + 1;
            P[i] = i/3;
        }
    }

    cout << D[X] << '\n';

    int cur = X;
    while (true) {
        cout << cur << ' ';
        if (cur == 1) break;
        cur = P[cur];
    }
    cout << '\n';

    return 0;
}