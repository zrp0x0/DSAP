#include <bits/stdc++.h>
using namespace std;

int freq[26];
int main() {
    string str;
    cin >> str;
    for (auto c : str) {
        freq[c - 'a']++;
    }
    for (int& c : freq) {
        cout << c << ' ';
    }
    cout << '\n';
    return 0;
}