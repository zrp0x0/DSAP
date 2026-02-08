#include <iostream>

void func1(uint16_t N) // O(N) -> O(1)
{
    uint64_t sum = 0;
    for (int i = 0; i <= N; i++) 
    {
        if (i % 3 == 0 || i % 5 == 0) 
        {
            sum += i;
        }
    }

    std::cout << sum << '\n';
    return;
}

void func2(int arr[], int N) // O(N^2) -> O(N)
{
    for (int i = 0; i < N; i++) 
    {
        for (int j = i + 1; j < N; j++)
        {
            if (arr[i] + arr[j] == 100)
            {
                std::cout << 1 << '\n';
                return;
            }
        }
    }
    std::cout << 0 << '\n';
    return;
}

void func3(int N) // O(root(N)) -> O(lgN)
{
    for (int i = 0; i * i <= N; i++)
    {
        if (i * i == N)
        {
            std::cout << 1 << '\n';
            return;
        }
    }
    std::cout << 0 << '\n';
    return;
}

void func4(int N) // O(lgN)
{
    int val = 1;
    while (val * 2 <= N) val *= 2;
    std::cout << val << '\n';
}
// k번만큼 실행됨 O(k) -> 2^k = N -> k = lgN

int main() 
{
    // func1(16);
    // func1(34567);
    // func1(27639);

    // int arr1[] = {1, 52, 48};
    // func2(arr1, 3);

    // int arr2[] = {50, 42};
    // func2(arr2, 3);

    // int arr3[] = {4, 13, 63, 87};
    // func2(arr3, 4);

    // func3(9);
    // func3(693953651);
    // func3(756580036);

    func4(5);
    func4(97615282);
    func4(1024);

    return 0;
}
