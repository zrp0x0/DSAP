#include <bits/stdc++.h>
using namespace std;

int N = 9;
int arr[] = { 9, 5, 3, 6, 1, 4, 7, 6, 6 };
int tmp[9];

void bubble_sort() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1 - i; j++) {
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }    
}

void merge(int st, int en) {
    int mid = (st + en) / 2;
    int lidx = st;
    int ridx = mid;
    for (int i = st; i < en; i++) {
        if (lidx == mid) tmp[i] = arr[ridx++];
        else if (ridx == en) tmp[i] = arr[lidx++];
        else if (arr[lidx] <= arr[ridx]) tmp[i] = arr[lidx++];
        else tmp[i] = arr[ridx++];
    }

    for (int i = st; i < en; i++) 
        arr[i] = tmp[i];
}

void merge_sort(int st, int en) {
    if (en - st == 1) return;
    int mid = (st + en) / 2;
    merge_sort(st, mid);
    merge_sort(mid, en);
    merge(st, en);
}

void quick_sort(int st, int en) {
    if (en - st <= 1) return;
    int tmp = arr[st];
    int l = st + 1;
    int r = en - 1;
    while (true) {
        while (l <= r && arr[l] <= tmp) l++;
        while (l <= r && arr[r] >= tmp) r--;
        if (l > r) break;
        swap(arr[l], arr[r]);
    }
    swap(arr[st], arr[r]);
    quick_sort(st, r);
    quick_sort(r+1, en);
}

void print_arr() {
    for (int i = 0; i < N; i++) 
        cout << arr[i] << ' ';
    cout << '\n';
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // bubble_sort();
    // merge_sort(0, N);
    quick_sort(0, N);

    print_arr();

    return 0;
}