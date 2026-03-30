#include <bits/stdc++.h>
using namespace std;

int N;
int d[10005];
int mod = 10007;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    d[1] = 1;
    d[2] = 2;
    for (int i = 3; i <= N; i++)
        d[i] = (d[i-1]+d[i-2]) % mod; // int overflow가 일어날 수도 있음
    cout << d[N];
    return 0;
}