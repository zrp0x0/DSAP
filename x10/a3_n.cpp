#include <bits/stdc++.h>
using namespace std;

int N, S, ans;
int D[305];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;

    for (int i = 1; i <= 3; i++) {
        cin >> D[i];
        ans += D[i];
    }

    for (int i = 4; i <= N; i++) {
        cin >> S;
        ans += S;
        D[i] = min(D[i-2], D[i-3]) + S;
    }
    
    cout << ans - min(D[N-1], D[N-2]) << '\n'; 

    return 0;
}

