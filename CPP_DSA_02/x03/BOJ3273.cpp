#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, arr[2000001] = {}, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        arr[a]++;
    }

    cin >> x;
    int cnt = 0;
    for (int i = 1; i < 2000001; i++) {
        if (arr[i] != 0) {
            if (x > i && arr[x - i] == 1 && i != x - i) {
                cnt++;
                arr[i]++;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}

// 별해
int a[2000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, t, x, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        a[t]++;
    }

    cin >> x;
    for (int i = 1; i < (x+1)/2; i++) { // 이걸 왜 하냐면 x가 짝수 / 홀수 두 경우 (그리고 서로 다른 a 즉 12일 경우 6은 검사할 이유가 없음) / 13인 경우 6까지만 검사하면 됨 어차피 6만 검사하면 7이 있는지를 확인할 수 있음
        if (a[i] == 1 && a[x-i] == 1) ans++;
    }
    cout << ans;
}
