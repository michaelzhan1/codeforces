#include <iostream>
#include <cmath>

int main()
{
    int a, b;
    std::cin >> a >> b;

    float tmp = log(float(b) / a) / log(1.5);
    int years = floor(tmp + 1);
    std::cout << years << std::endl;
    return 0;
}
