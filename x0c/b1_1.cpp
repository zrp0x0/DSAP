#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
int vis[10];

void func(int k) {
    if (k == M) {
        for (int i = 0; i < M; i++) 
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (!vis[i]) {            
            if (k != 0 && arr[k - 1] > i)
                continue;
            
            vis[i] = 1;
            arr[k] = i;
            func(k+1);
            vis[i] = 0;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    func(0);

    return 0;
}