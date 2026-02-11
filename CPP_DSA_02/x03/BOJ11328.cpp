#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str1, str2;
        cin >> str1 >> str2;

        int str1_arr[26] = {0, };

        for (char c1 : str1) {
        str1_arr[c1 - 'a']++;
        }

        for (char c2 : str2) {
            str1_arr[c2 - 'a']--;
        }

        bool flag = true;
        for (int i : str1_arr) {
            if (i != 0) {
                flag = false;
                break;
            }
        }

        if (flag) {
            cout << "Possible\n";
        } else {
            cout << "Impossible\n";
        }
    }

    return 0;
}

/*
> 배열을 두 개 사용하고 그 두 개가 결국 동일한지? 확인했는데, 
> 그냥 하나를 사용하고 빼는 방식으로 모든 원소가 0인지를 판별하도록
*/
