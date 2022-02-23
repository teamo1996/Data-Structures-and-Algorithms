#include <iostream>

int EuclidGCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return EuclidGCD(b, a % b);
    }
}

int main()
{
    int a = 0;
    int b = 0;
    std::cin >> a >> b;

    int number1 = std::max(a, b);
    int number2 = std::min(a, b);

    std::cout << EuclidGCD(number1, number2) << std::endl;

    return 0;
}