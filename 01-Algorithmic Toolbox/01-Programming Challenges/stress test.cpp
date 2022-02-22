#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

long long MaxPairwiseProductFast(const std::vector<int> &numbers)
{
    long long max_product = 0;
    int n = numbers.size();

    int max_index1 = 0;
    int max_index2 = n - 1;

    for (int i = 0; i < n; ++i)
    {
        if (numbers[i] > numbers[max_index1])
        {
            max_index2 = max_index1;
            max_index1 = i;
        }
        else if (numbers[i] > numbers[max_index2] && i != max_index1)
        {
            max_index2 = i;
        }
        else
        {
        }
    }

    max_product = (long long)numbers[max_index1] * (long long)numbers[max_index2];

    return max_product;
}

long long MaxPairwiseProductslow(const std::vector<int> &numbers)
{
    long long max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first)
    {
        for (int second = first + 1; second < n; ++second)
        {
            int result =
                max_product = std::max(max_product,
                                       ((long long)numbers[first] * (long long)numbers[second]));
        }
    }

    return max_product;
}

int main()
{
    // 压力测试
    while (true)
    {
        int n = rand() % 100 + 2;
        std::cout << n << "\n";

        std::vector<int> a;
        for (int i = 0; i < n; ++i)
        {
            a.push_back(rand() % 100000);
        }
        for (int i = 0; i < n; ++i)
        {
            std::cout << a[i] << " ";
        }
        std::cout << "\n";
        long long res1 = MaxPairwiseProductslow(a);
        long long res2 = MaxPairwiseProductFast(a);

        if (res1 != res2)
        {
            std::cout << "Wrong answer" << res1 << " " << res2 << "\n";
            break;
        }
        else
        {
            std::cout << "OK\n";
        }
    }

    // int n;
    // std::cin >> n;
    // std::vector<int> numbers(n);
    // for (int i = 0; i < n; ++i)
    // {
    //     std::cin >> numbers[i];
    // }

    // std::cout << MaxPairwiseProductFast(numbers) << "\n";
    return 0;
}