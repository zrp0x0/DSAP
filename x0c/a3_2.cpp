#include <bits/stdc++.h>
using namespace std;

int N, S;
int arr[30];
int cnt;

void func(int cur, int tot) {
    if (cur == N) {
        if (tot == S)
            cnt++;
        return;
    }

    func(cur + 1, tot); // 포함되지 않았을 때
    func(cur + 1, tot + arr[cur]); // 포함되었을 때
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> S;
    for (int i = 0; i < N; i++) 
        cin >> arr[i];
    
    func(0, 0);
    if (S == 0) // 0이면 공집합이 포함될 수 있으므로 -1을 해주어야함
        cnt--;
    cout << cnt << '\n';

    return 0;
}
