#include <bits/stdc++.h>
using namespace std;

int main() 
{
    // int a, b, c;
    // cin >> a >> b >> c;
    // string mul = to_string(a * b * c);
    // int arr[10] = {0, };
    // for (auto c : mul) {
    //     arr[c - '0']++;
    // }
    // for (auto c : arr) {
    //     cout << c << '\n';
    // }

    int a, b, c, mul, arr[10] = {};
    cin >> a >> b >> c;
    mul = a * b * c;
    while (mul) {
        arr[mul%10]++;
        mul /= 10;
    }

    for (int v : arr) {
        cout << v << '\n';
    }

    return 0;
}