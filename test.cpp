#include <bits/stdc++.h>
using namespace std;

int N, M, ans = 999;
char arr[51][51];

void counting(int stN, int stM, char target) {
    int min = 0;

    for (int i = stN; i < stN + 8; i++) {
        for (int j = stM; j < stM + 8; j++) {
            if (arr[i][j] != target) {
                min++;
            }
            target = (target == 'W' ? 'B' : 'W');
        }
        target = (target == 'W' ? 'B' : 'W');
    }

    if (ans > min) ans = min;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> arr[i][j];

    int stN = 0;
    int stM = 0;

    for (int i = 0; i < N - 8 + 1; i++) {
        for (int j = 0; j < M - 8 + 1; j++) {
            // 시작을 W로 하는 경우
            counting(stN + i, stM + j, 'W');

            // 시작을 B로 하는 경우
            counting(stN + i, stM + j, 'B');
        }
    }

    cout << ans << '\n';

    return 0;
}