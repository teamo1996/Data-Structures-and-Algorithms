#include <iostream>
#include <vector>

int get_fibonacci_last_digit_naive(int n)
{
    std::vector<int> list(2, 0);
    list[1] = 1;
    if (n <= 1)
    {
        return list[n];
    }

    for (int i = 2; i <= n; ++i)
    {
        int sum = (list[0] + list[1]) % 10;
        list[0] = list[1];
        list[1] = sum;
    }

    return list[1];
}

int main()
{
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_naive(n);
    std::cout << c << '\n';
}
