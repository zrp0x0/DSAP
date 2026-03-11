#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
int ans[10];

void func(int k) {
    if (k == M) {
        for (int i = 0; i < M; i++)
            cout << ans[i] << ' ';
        cout << '\n';
        return;
    }

    int tmp = 0;
    for (int i = 0; i < N; i++) {
        if (k != 0 && ans[k - 1] > arr[i]) continue;

        if (tmp != arr[i]) {
            ans[k] = arr[i];
            tmp = arr[i];
            func(k + 1);
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

    sort(arr, arr + N);

    func(0);

    return 0;
}