#include <bits/stdc++.h>
using namespace std;

int N;
int ans;
bool isused1[15];
bool isused2[15 * 2 - 1];
bool isused3[15 * 2 - 1];

void func(int k) {
    if (k == N) {
        ans++;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!isused1[i] && !isused2[k + i] && !isused3[k - i + N - 1]) {
            isused1[i] = 1;
            isused2[k + i] = 1;
            isused3[k - i + N - 1] = 1;

            func(k + 1);

            isused1[i] = 0;
            isused2[k + i] = 0;
            isused3[k - i + N - 1] = 0;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    func(0);
    cout << ans << '\n';

    return 0;
}

/*
> 가지치기가 많아지면 시간복잡도 가늠하기가 힘듦
> N이 매우 작아서 일단 백트래킹 같으면 돌려보고
> 가장 시간이 오래 걸리만한 케이스를 직접 돌려보고 시간초과가 나는지 안나는지 보면 됨
    - 여기서는 14를 넣어보기
> Release Mode로 돌리기
> 보통은 로컬보다 서버가 더 빠름
*/