#include <iostream>
#include <cmath>

int main()
{
    int n;
    std::cin >> n;

    if (n % 5 == 0) {
        std::cout << n / 5 << std::endl;
    }
    else
    {
        std::cout << ceil(n / 5.0) << std::endl;
    }
    return 0;
}
