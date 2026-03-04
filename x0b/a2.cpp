#include <bits/stdc++.h>
using namespace std;

void func(int from, int to, int N) {
    if (N == 1) {
        cout << from << ' ' << to << '\n';
        return;
    }
        

    func(from, 6 - from - to, N - 1);
    cout << from << ' ' << to << '\n';
    func(6 - from - to, to, N - 1);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    unsigned int a = 1;
    cout << (a << N) - 1 << '\n';
    func(1, 3, N);

    return 0;
}