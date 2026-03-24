#include <bits/stdc++.h>
using namespace std;

int T; // <= 10
int N;
int D[11];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    D[1] = 1;
    D[2] = 2;
    D[3] = 4;
    for (int i = 4; i <= 11; i++) {
        D[i] = D[i-1] + D[i-2] + D[i-3];
    }

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        cout << D[N] << '\n';
    }

    return 0;
}

// N이 주어질 때마다 새로 구하는 것보다 어차피 미리 구하고 꺼내서 쓸 수 있는 상황이면 이렇게 구현