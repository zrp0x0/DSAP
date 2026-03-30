#include <bits/stdc++.h>
using namespace std;

vector<string> V(3);
int tmp, idx;

string made(int tmp, int idx) {
    string str;
    while (idx != 3) {
        idx++;
        tmp++;
        if (tmp % 3 == 0 && tmp % 5 == 0) {
            str = "FizzBuzz";
        } else if (tmp % 3 != 0 && tmp % 5 == 0) {
            str = "Buzz";
        } else if (tmp % 3 == 0 && tmp % 5 != 0) {
            str = "Fizz";
        } else {
            str = to_string(tmp);
        }
    }
    return str;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i < 3; i++) {
        cin >> V[i];
        if (V[i] != "Fizz" && V[i] != "Buzz" && V[i] != "FizzBuzz") {
            tmp = stoi(V[i]);
            idx = i;
        }
    }
    
    cout << made(tmp, idx) << '\n';
    
    return 0;
}