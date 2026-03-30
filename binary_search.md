# 이진 탐색

## 알고리즘 설명

### 이진 탐색
- **정렬이 되어 있는 배열**에서 특정 데이터를 찾기 위해 모든 데이터를 순차적으로 확인하는 대신 탐색 범위를 절반으로 줄여가며 찾는 탐색 방법

### 선형 탐색 vs 이진 탐색
- 선형 탐색: 2 4 6 13 16 19 22 23 30 32
- 이진 탐색: 2 4 6 13 16 19 22 23 30 32

--- 

## 구현 및 STL

### 이론 수 찾기 - _ 찾기
- st / mid / en 

- 2 4 6 13 16 19 22 23 30 32
- st = 2
- mid = 16
- en = 32

- _ > mid => st = mid + 1
- _ < mid => en = mid - 1

- _ == mid: 찾음!!

### 구현
```cpp
#include <bits/stdc++.h>
using namespace std;

int N = 8;
int arr[] = {5, 6, 8, 10, 12, 15, 19, -2};

int binary_search(int st, int en, int target) {
    if (st > en) return -1; // 탐색 실패 시 -1 반환

    int mid = (st + en) / 2;

    if (arr[mid] == target) return mid; // 값을 찾은 경우

    if (arr[mid] < target) {
        return binary_search(mid + 1, en, target);
    } else if (arr[mid] > target) {
        return binary_search(st, mid - 1, target);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    sort(arr, arr+N);
    int result = binary_search(0, N-1, 19);

    if (result != -1) {
        cout << "원소를 찾았습니다. 인덱스: " << result << '\n';
    } else {
        cout << "원소를 찾을 수 없습니다\n" << '\n';
    }

    return 0;
}
```

### 시간 복잡도
- O(logN)

---

## 주의사항
- 정렬 필수: 데이터가 반드시 오름차순 또는 내림차순으로 정렬된 상태여야함
- 임의 접근 가능: 배열처럼 인덱스를 통해 특정 위치에 접근할 수 있는 구조에서 효율적임

---

## 활용: 10816번 숫자 카드 2
- 배열 트릭 활용
```cpp
#include <bits/stdc++.h>
using namespace std;
#define MI 10000000

int N, M, tmp;
int arr[20000001];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        arr[tmp + MI]++;
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> tmp;
        cout << arr[tmp + MI] << ' ';
    }
    
    return 0;
}
```

- 이진 탐색 풀이
```cpp
#include <bits/stdc++.h>
using namespace std;

int a[5000005];
int n;

// n = 9
// 1 2 3 4 5 5 5 6 7 / target 5

int lower_idx(int target, int len) { // 처음 등장하는 곳
    int st = 0;
    int en = len;
    while (st < en) {
        int mid = (st + en) / 2;
        if (a[mid] >= target) en = mid;
        else st = mid + 1;
    }
    return st;
}

int upper_idx(int target, int len) { // 가장 나중에 등장하는 곳
    int st = 0;
    int en = len;
    while (st < en) {
        int mid = (st + en) / 2;
        if (a[mid] > target) en = mid;
        else st = mid + 1;
    }
    return st;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    sort(a, a+n);

    int m;
    cin >> m;

    while (m--) {
        int t;
        cin >> t;
        cout << upper_idx(t, n) - lower_idx(t, n) << '\n';
    }

    return 0;
}
```