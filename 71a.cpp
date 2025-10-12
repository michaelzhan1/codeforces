#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    std::cin.ignore();

    for (int i = 0; i < n; i++)
    {
        std::string word;
        std::getline(std::cin, word);

        size_t len = word.length();
        if (len <= 10)
        {
            std::cout << word << std::endl;
        }
        else
        {
            std::cout << word[0] << len - 2 << word[len - 1] << std::endl;
        }
    }

    return 0;
}