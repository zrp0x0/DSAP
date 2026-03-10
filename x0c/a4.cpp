#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[3] = {1, 2, 3};
    do {
        for (int i = 0; i < 3; i++) 
            cout << a[i];
        cout << '\n';
    } while (next_permutation(a, a+3));

    int b[4] = {0, 0, 1, 1};
    do {
        for (int i = 0; i < 4; i++) {
            if (b[i] == 0) 
                cout << i + 1;
        }  
        cout << '\n';
    } while (next_permutation(b, b+4));
    

    return 0;
}

/*
> 순열 구하기
- 현재 순열을 사전순으로 만들고 true
- 만들 순열이 더 없다면 false를 반환

- 사전순!!
- 중복도 해줌
*/