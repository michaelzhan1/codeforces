#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int a, b, c;

    int res = 0;

    for (int i = 0; i < n; i++)
    {
        std::cin >> a >> b >> c;
        
        res += a + b + c >= 2;
    }
    std::cout << res << std::endl;

    return 0;
}
