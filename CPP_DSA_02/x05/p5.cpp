#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<long long> tower;
    tower.push(1000000001);

    int n;
    long long ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int height;
        cin >> height;
        
        while (tower.top() <= height)
            tower.pop();
        ans += tower.size() - 1L;
        tower.push(height);
    }

    cout << ans << '\n';

    return 0;
}