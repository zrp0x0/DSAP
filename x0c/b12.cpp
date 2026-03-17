#include <bits/stdc++.h>
using namespace std;

int N; 
int arr[13];
int vis[13];
int ans[13];

void func(int k) {
    if (k == 6) {
        for (int i = 0; i < 6; i++) 
            cout << ans[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++) {

        if (k != 0 && ans[k - 1] > arr[i]) continue;

        if (!vis[i]) {
            vis[i] = 1;
            ans[k] = arr[i];
            func(k+1);
            vis[i] = 0;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        cin >> N;
        if (N == 0) break;

        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        func(0);
        cout << '\n';
    }

    return 0;
}

/**
 * 8 * 7 * 6 * 5 * 4 * 3: 20160
 * 6 * 5 * 4 * 3 * 2 * 1: 
 */