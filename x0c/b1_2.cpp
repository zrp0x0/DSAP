#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    // N개중에 M개
    // {0 0 0 1}
    for (int i = 0; i < N; i++) {
        if (i < M)
            arr[i] = 0;
        else
            arr[i] = 1;
    }

    do {
        for (int i = 0; i < N; i++) {
            if (arr[i] == 0)
                cout << i + 1 << ' ';
        }
        cout << '\n';
    } while (next_permutation(arr, arr+N));

    return 0;
}