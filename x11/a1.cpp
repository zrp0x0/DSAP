#include <bits/stdc++.h>
using namespace std;

int N, K, ans;
int arr[10];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = N - 1; i >= 0; i--) {
        if (K == 0) break;
        if (arr[i] > K) continue;
        ans += K / arr[i];
        K = K % arr[i];
    }

    cout << ans << '\n';

    return 0;
}