#include <bits/stdc++.h>
using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     vector<int> vec;
//     stack<int> stk;

//     int n;
//     cin >> n;
//     while (n--) {
//         int c;
//         cin >> c;
//         vec.push_back(c);
//     }

//     for (int i = vec.size() - 1; i > 0; i--) { // 4 3 2 1
//         bool flag = false;
//         for (int j = i - 1; j > -1; j--) { // 3 2 1 0
//             if (vec[i] < vec[j]) {
//                 stk.push(j+1);
//                 flag = true;
//                 break;
//             }
//         }

//         if (flag == false) {
//             stk.push(0);
//         }

//     }
//     stk.push(0); // 그냥 첫번째는 항상 0일 수 밖에 없음

//     while (!stk.empty()) {
//         cout << stk.top() << ' ';
//         stk.pop();
//     } 
//     cout << '\n';

//     return 0;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     stack<int> stk;
//     stack<int> number;

//     int n;
//     int count = 0;
//     cin >> n;
//     for (int i = 1; i <= n; i++) {
//         int v;
//         cin >> v;

//         while (true) {
//             if (stk.empty()) {
//                 cout << 0 << ' ';
//                 stk.push(v);
//                 number.push(i);
//                 break;
//             } else {
//                 if (stk.top() < v) {
//                     stk.pop();
//                     number.pop();
//                 } else {
//                     cout << number.top() << ' ';
//                     stk.push(v);
//                     number.push(i);
//                     break;
//                 }
//             }
//         }

        
//     }

//     return 0;
// }

#define X first
#define Y second

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<pair<int, int>> tower;
    tower.push({100000001, 0});

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int height;
        cin >> height;

        while (tower.top().X < height) {
            tower.pop();
        }
        cout << tower.top().Y << ' ';
        tower.push({height, i});
    }

    return 0;
}

