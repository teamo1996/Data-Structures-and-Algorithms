#include <iostream>
#include <vector>
#include <math.h>

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

long long get_fibonacci_huge_fast(long long n, long long m)
{
    std::vector<long long> list(2, 0);
    long long length = pisano(m);
    // std::cout << length << std::endl;
    list[1] = 1;
    if (n <= 1)
    {
        return list[n];
    }

    for (int i = 2; i < length; ++i)
    {
        long long sum = (list[i - 1] % m + list[i - 2] % m) % m;
        // std::cout << sum << " " << std::endl;
        list.push_back(sum);
    }

    return list[n % length];
}

long long get_fibonacci_huge_naive(long long n, long long m)
{
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;

    for (long long i = 0; i < n - 1; ++i)
    {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

int main()
{
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
