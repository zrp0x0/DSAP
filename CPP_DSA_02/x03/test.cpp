#include <bits/stdc++.h>
using namespace std;

int grr[101];

void func2(int arr[], int N) // O(N^2) -> **O(N)**
{
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (grr[100 - arr[i]]) {
            cnt++;
        }
        grr[arr[i]]++;
    }
    cout << cnt << "\n";
}

int main() {
    int arr1[] = {50, 42};
    func2(arr1, 1);
}