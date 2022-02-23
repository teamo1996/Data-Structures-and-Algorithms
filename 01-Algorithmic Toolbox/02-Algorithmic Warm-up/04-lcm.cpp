#include <iostream>

long long gcd_Euclid(long a, long b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd_Euclid(b, a % b);
    }
}

long long lcm_fast(long long a, long long b)
{

    return (a * b) / gcd_Euclid(a, b);
}

int main()
{
    long long a, b;
    std::cin >> a >> b;
    std::cout << lcm_fast(a, b) << std::endl;
    return 0;
}
