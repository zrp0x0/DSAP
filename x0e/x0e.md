# 0x0E 정렬 1

## 기초 정렬 - 버블 정렬

### 구현
```cpp
void bubble_sort() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1 - i; j++) {
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }    
}
```

---

## Merge Sort

### 구현
```cpp
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
```

---

## Quick Sort

### 구현
```cpp
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
```