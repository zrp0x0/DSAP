#include <bits/stdc++.h>
using namespace std;

int n = 10;
int arr[1000001] = {3, 4, 5, 7, 1, 2, 9, 10, 11, 12};
int tmp[1000001];

void merge(int st, int en) {
    int mid = (st+en) / 2;
    int aidx = st;
    int bidx = mid;
    for (int i = st; i < en; i++) {
        if (aidx == mid) {
            tmp[i] = arr[bidx++];
        } else if (bidx == en) {
            tmp[i] = arr[aidx++];
        } else if (arr[aidx] <= arr[bidx]) {
            tmp[i] = arr[aidx++];
        } else {
            tmp[i] = arr[bidx++];
        }
    }

    for (int i = st; i < en; i++) {
        arr[i] = tmp[i];
    }
}

void merge_sort(int st, int en) {
    if (st == en - 1) return;
    int mid = (st+en) / 2;
    merge_sort(st, mid);
    merge_sort(mid, en);
    merge(st, en);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    merge_sort(0, n);
    for (int i = 0; i< n; i++)
        cout << arr[i] << ' ';
    
    return 0;
}
