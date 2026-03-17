#include <bits/stdc++.h>
using namespace std;

int N = 9;
int arr[] = {5, 4, 1, -2, 3, 4, 16, 20, 0};

void quick_sort(int st, int en) {
    if (en - st <= 1) return;

    int pivot = arr[st];
    int l = st + 1;
    int r = en - 1;

    while (true) {
        while (l <= r && arr[l] < pivot) l++;
        while (l <= r && arr[r] >= pivot) r--;
        if (l > r) break;
        swap(arr[l], arr[r]);
    }

    swap(arr[st], arr[r]);
    quick_sort(st, r);
    quick_sort(r+1, en);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    quick_sort(0, N);
    for (int i = 0; i < N; i++) 
        cout << arr[i] << ' ';
    cout << '\n';
    return 0;
}

/*
> 평균: O(NlogN) => 같은 NlogN이여도 병합보다 빠름 => Why
> 최악: O(N^2) => 이미 원하는 방향으로 정렬되어있는 경우

> 병합 vs 퀵
- 시간복잡도: O(NlogN) vs O(NlogN), O(N^2)
- 공갑복잡도: O(N) vs O(1)
- stable: O vs X -> Why
*/