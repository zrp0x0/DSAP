#include <bits/stdc++.h>
using namespace std;

int a[5000005];
int n;

//
// 1 2 3 4 5 5 5 6 7 / target 5

int lower_idx(int target, int len) { // 처음 등장하는 곳
    int st = 0;
    int en = len;
    while (st < en) {
        int mid = (st + en) / 2;
        if (a[mid] >= target) en = mid;
        else st = mid + 1;
    }
    return st;
}

int upper_idx(int target, int len) { // 가장 나중에 등장하는 곳
    int st = 0;
    int en = len;
    while (st < en) {
        int mid = (st + en) / 2;
        if (a[mid] > target) en = mid;
        else st = mid + 1;
    }
    return st;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    sort(a, a+n);

    int m;
    cin >> m;

    while (m--) {
        int t;
        cin >> t;
        cout << upper_idx(t, n) - lower_idx(t, n) << '\n';
    }

    return 0;
}