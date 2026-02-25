// BOJ 1629번: 곱셈
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int func1(ll a, ll b, ll c) {
    if (b == 1)
        return a % c;

    ll val = func1(a, b/2, c) % c;
    val = val * val % c;

    if (b % 2 != 0)
        val = val * a % c;

    return val;
}

int func2(ll a, ll b, ll c) {
    
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a, b, c;
    cin >> a >> b >> c;
    cout << func1(a, b, c) << '\n';
    return 0;
}

/*
> 사용된 개념
- a^b mod m을 overflow 안나게 하고 하기
- 재귀적(귀납적) 사고로 생각하기

- a^n * a^n = a^2n

- 반목문으로 구현해보기
*/