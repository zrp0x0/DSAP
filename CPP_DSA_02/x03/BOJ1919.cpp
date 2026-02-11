#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ans = 0;
    string str1, str2;
    cin >> str1 >> str2;
    int arr[26] = {0, };
    for (char c : str1) {
        arr[c - 'a']++;
    }

    for (char c : str2) {
        arr[c - 'a']--;
    }

    for (int i : arr) {
        ans += abs(i);
    }

    cout << ans << '\n';

    return 0;
}
