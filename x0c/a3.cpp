#include <bits/stdc++.h>
using namespace std;

int N, S;
int ans;
int arr[22];
int sum;

void func(int k) {
    if (k == N) {
        return;
    }

    sum += arr[k];
    if (sum == S)
        ans++;
    func(k+1);
    sum -= arr[k];

    func(k+1);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    func(0);
    cout << ans << '\n';

    return 0;
}

/*
> 의도하진 않았지만 공집합은 == 크기가 양수인 부분수열
*/