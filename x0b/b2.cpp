#include <bits/stdc++.h>
using namespace std;

int arr[2200][2200];
int cnt[3]; // -1 0 1

bool check(int N, int ir, int ic) {
    for (int i = ir; i < ir + N; i++) {
        for (int j = ic; j < ic + N; j++) {
            if (arr[ir][ic] != arr[i][j])
                return false;
        }
    }
    return true;
}

void func(int N, int ir, int ic) {
    if (check(N, ir, ic)) {
        cnt[arr[ir][ic] + 1]++;
        return;
    }

    int split = N / 3;

    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            func(split, ir + x * split, ic + y * split);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    func(N, 0, 0);

    for (int i = 0; i < 3; i++) {
        cout << cnt[i] << '\n';
    }

    return 0;
}