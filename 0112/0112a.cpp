#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::string a, b;
    std::getline(std::cin, a);
    std::getline(std::cin, b);

    std::transform(a.begin(), a.end(), a.begin(), ::tolower);
    std::transform(b.begin(), b.end(), b.begin(), ::tolower);

    if (a > b)
    {
        std::cout << 1 << std::endl;
    }
    else if (a < b)
    {
        std::cout << -1 << std::endl;
    }
    else
    {
        std::cout << 0 << std::endl;
    }
    return 0;
}
