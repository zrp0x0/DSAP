#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr1[1000001];
int arr2[1000001];
int arr3[2000001];
int p1, p2;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr1[i];
    }   
    
    for (int i = 0; i < M; i++) {
        cin >> arr2[i];
    }

    int aidx = 0, bidx = 0;
    for (int i = 0; i < N + M; i++) {
        if (aidx == N) 
            arr3[i] = arr2[bidx++];
        else if (bidx == M)
            arr3[i] = arr1[aidx++];
        else if (arr1[aidx] <= arr2[bidx]) // stable sort
            arr3[i] = arr1[aidx++];
        else 
            arr3[i] = arr2[bidx++];
    }

    for (int i = 0; i < N + M; i++) {
        cout << arr3[i] << ' ';
    }
    cout << '\n';

    return 0;
}