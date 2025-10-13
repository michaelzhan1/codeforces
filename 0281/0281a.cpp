#include <iostream>
#include <string>

int main()
{
    std::string word;
    std::getline(std::cin, word);
    std::cout << char(toupper(word[0])) << word.substr(1) << std::endl;
    return 0;
}
