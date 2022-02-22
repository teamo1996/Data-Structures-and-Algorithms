#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<int> &numbers)
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

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}