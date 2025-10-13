#include <iostream>
#include <string>

int main()
{
    std::string name;
    std::getline(std::cin, name);

    bool chars[26] = {false};

    for (char c : name)
        chars[c - 'a'] = true;

    int count = 0;
    for (bool b : chars)
    {
        count += b;
    }

    if (count % 2 == 1)
    {
        std::cout << "IGNORE HIM!" << std::endl;
    }
    else
    {
        std::cout << "CHAT WITH HER!" << std::endl;
    }

    return 0;
}
