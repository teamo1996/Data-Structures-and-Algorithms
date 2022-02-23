#include <iostream>
#include <vector>

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

int fibonacci_sum_fast(long long n)
{
    int length = pisano(10);
    std::vector<long long> list(2, 0);
    // std::cout << length << std::endl;
    list[1] = 1;
    if (n <= 1)
    {
        return list[n];
    }
    int total = 1;

    for (int i = 2; i < length; ++i)
    {
        long long sum = (list[i - 1] % 10 + list[i - 2] % 10) % 10;
        // std::cout << sum << " " << std::endl;
        list.push_back(sum);
        total = (total + sum) % 10;
    }

    // std::cout << total << std::endl;

    int sum = 0;

    for (int i = 0; i < (int)n / length; ++i)
    {
        sum = (sum + total) % 10;
    }

    // std::cout << sum << std::endl;

    for (int i = 0; i <= (int)(n % length); ++i)
    {
        sum = (sum + list[i]) % 10;
        // std::cout << list[i] << " " << std::endl;
    }

    return sum;
}

int main()
{
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
}
