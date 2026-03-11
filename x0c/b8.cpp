#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
int ans[10];
int vis[10];
unordered_set<string> S;

void func(int k) {
    if (k == M) {
        string key = "";

        for (int i = 0; i < M; i++) {
            key += to_string(ans[i]);
            key += " ";
        }

        if (S.find(key) != S.end()) {
            return;
        } else {
            S.insert(key);

            cout << key << '\n';
            return;
        }
    }

    for (int i = 0; i < N; i++) {
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
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+N);
    func(0);
    return 0;
}