#include <bits/stdc++.h>
using namespace std;

int N;
string line;

string num;

bool func() {

    queue<char> Q;
    deque<string> D;

    for (int i = 0; i < 3; i++) {
        getline(cin, line);
        if (i == 0) {
            int n = line.length();
            int idx = 0;
            while (n--) {
                Q.push(line[idx++]);
            }
        }

        if (i == 2) {
            for (char c : line) {
                if (c == ']') {
                    if (num != "") {
                        D.push_back(num);
                    }
                    num = ""; 
                    break;
                }
                   
                
                if (isdigit(c)) {
                    num += c;
                } else if (c == ',') {
                    D.push_back(num);
                    num = "";
                }
            }
        }
    }

    bool DP = true; // front vs back
    while (!Q.empty()) {
        char c = Q.front(); Q.pop();

        if (c == 'R') {
            DP = !DP;
        } else {
            if (D.empty())
                return false;

            if (DP) {
                D.pop_front();
            } else {
                D.pop_back();
            }
        }
    }

    // 최종 출력
    cout << '[';
    while (!D.empty()) {
        if (DP) {
            if (D.size() == 1) {
                cout << D.front();
                D.pop_front();
            } else {
                cout << D.front() << ",";
                D.pop_front();
            }
            
        } else {
            if (D.size() == 1) {
                cout << D.back();
                D.pop_back();
            } else {
                cout << D.back() << ",";
                D.pop_back();
            }
        }
    }
    cout << "]\n";

    return true;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    cin.ignore();
    for (int i = 0; i < N; i++) {
        if (!func())
            cout << "error" << '\n';
    }

    return 0;
}