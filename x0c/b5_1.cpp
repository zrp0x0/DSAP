#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
int vis[10];
int ans[10];

void func(int k) {
    if (k == M) {
        for (int i = 0; i < M; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++) {
        if (vis[i] || k != 0 && ans[k-1] > arr[i]) continue;
     
        vis[i] = 1;
        ans[k] = arr[i];
        func(k+1);
        vis[i] = 0;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }

    func(0);

    return 0;
}