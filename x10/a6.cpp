#include <bits/stdc++.h>
using namespace std;

int N, M, tmp;
int x, y;
int D[100005];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    D[0] = 0;
    for (int i = 1; i <= N; i++) {
        cin >> tmp;
        D[i] = D[i-1] + tmp;
    }

    for (int i = 0; i < M; i++) {
        cin >> x >> y;    
        cout << D[y] - D[x-1] << '\n';
    }

    return 0;
}