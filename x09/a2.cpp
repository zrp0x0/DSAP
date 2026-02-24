// BOJ 9466번: 텀 프로젝트
#include <bits/stdc++.h>
using namespace std;

int arr[100002];
int sta[100002];

const int NOT_VISITED = 0;
const int VISITED = 1;
const int CYCLE_IN = 2;
const int NOT_CYCLE_IN = 3;

void run(int x) {
    int cur = x;
    while (true) {
        sta[cur] = VISITED;
        cur = arr[cur];

        if (sta[cur] == CYCLE_IN || sta[cur] == NOT_CYCLE_IN) {
            cur = x;
            while (sta[cur] == VISITED) {
                sta[cur] = NOT_CYCLE_IN;
                cur = arr[cur];
            }

            return;
        }

        if (sta[cur] == VISITED && cur != x) {
            while (sta[cur] != CYCLE_IN) {
                sta[cur] = CYCLE_IN;
                cur = arr[cur];
            }

            cur = x;
            while (sta[cur] != CYCLE_IN) {
                sta[cur] = NOT_CYCLE_IN;
                cur = arr[cur];
            }

            return ;
        }

        if (sta[cur] == VISITED && cur == x) {
            while (sta[cur] != CYCLE_IN) {
                sta[cur] = CYCLE_IN;
                cur = arr[cur];
            }
            return;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        for (int i = 1; i <= N; i++) {
            sta[i] = 0;
        }

        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
        }

        int ans = 0;
        for (int i = 1; i <= N; i++) {
            if (sta[i] == NOT_VISITED) run(i);
        }

        for (int i = 1; i <= N; i++) {
            if (sta[i] == NOT_CYCLE_IN) ans++;
        }

        cout << ans << '\n';
    }

    return 0;
}