#include <iostream>
#include <cmath>

long long ceilDiv(long long a, long long b)
{
    if (a % b == 0)
    {
        return a / b;
    }
    else
    {
        return ceil(a / float(b));
    }
}

int main()
{
    long long n, m, a;
    std::cin >> n >> m >> a;
    std::cout << ceilDiv(n, a) * ceilDiv(m, a) << std::endl;
    return 0;
}
