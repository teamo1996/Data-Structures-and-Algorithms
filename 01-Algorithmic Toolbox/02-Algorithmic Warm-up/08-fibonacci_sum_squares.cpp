#include <iostream>

long long pisano(long long m)
{
    long prev = 0;
    long curr = 1;
    long res = 0;

    for (int i = 0; i < m * m; i++)
    {
        long temp = 0;
        temp = curr;
        curr = (prev + curr) % m;
        prev = temp;

        if (prev == 0 && curr == 1)
            res = i + 1;
    }
    return res;
}

int fib(long long n)
{
    int pre = 0, cur = 1;
    n = n % pisano(10);
    if (n <= 1)
    {
        return n;
    }
    else
    {
        for (int i = 2; i <= n; i++)
        {
            int temp = (pre + cur) % 10;
            pre = cur;
            cur = temp;
        }
    }

    return (cur);
}

int fibonacci_sum_squares_fast(long long n)
{
    return (fib(n) * fib(n + 1)) % 10;
}

int main()
{
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_fast(n);
}
