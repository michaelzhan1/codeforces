#include <iostream>
#include <string>

int main()
{
    int n;
    std::cin >> n;
    std::cin.ignore();
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        std::string cmd;
        std::getline(std::cin, cmd);
        if (cmd[1] == '-')
        {
            x--;
        }
        else
        {
            x++;
        }
    }
    std::cout << x << std::endl;
    return 0;
}