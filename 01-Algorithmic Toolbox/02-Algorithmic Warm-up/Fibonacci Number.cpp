#include <iostream>
#include <vector>

long long FibonacciNumber(int n)
{
    std::vector<long long> list(2, 0);
    list[1] = 1;
    if (n <= 1)
    {
        return list[n];
    }

    for (int i = 2; i <= n; ++i)
    {
        int sum = list[0] + list[1];
        list[0] = list[1];
        list[1] = sum;
    }

    return list[1];
}

int main()
{
    int n = 0;
    std::cin >> n;
    std::cout << FibonacciNumber(n) << "\n";
    return 0;
}