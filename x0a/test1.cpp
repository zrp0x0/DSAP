#include <iostream>
using namespace std;

void test1(int N) {
    if (N == 0) return;
    cout << N << ' ';
    test1(N - 1);
}

int test2(int N) {
    if (N == 1)
        return 1;
    return N + test2(N - 1);
}

int main(void) {

    test1(5);
    cout << test2(5) << '\n';

    return 0;
}