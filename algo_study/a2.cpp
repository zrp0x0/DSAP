// BOJ: 10808
#include <bits/stdc++.h>
using namespace std;

string str;
int arr[50];

// [1] [2] [] [] [] [] [] .. 

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> str;
    for (char c : str) {
        arr[c - 'a']++;
    }

    for (char i = 'a' - 'a'; i <= 'z' - 'a'; i++) {
        cout << arr[i] << ' ';
    }

    cout << '\n';
    return 0;   
}

// 배열 트릭 사용하기
// - O(N)
