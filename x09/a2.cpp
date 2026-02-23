// BOJ 9466번: 텀 프로젝트
#include <bits/stdc++.h>
using namespace std;

int arr[100002];
int vis[100002];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
            vis[i] = 0;
        }

        queue<int> Q;

        for (int i = 1; i <= N; i++) {
            if (vis[i] == 0) {

            }
        }
    }

    return 0;
}