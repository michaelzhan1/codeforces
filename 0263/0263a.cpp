#include <iostream>
#include <string>

int main()
{
    int val;
    for (int i = 0; i < 25; i++)
    {
        std::cin >> val;
        if (val == 1) {
            int row = i / 5;
            int col = i % 5;
            std::cout << abs(row - 2) + abs(col - 2) << std::endl;
            break;
        }
    }

    return 0;
}
