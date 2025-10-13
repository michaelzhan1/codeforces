#include <iostream>
#include <string>
#include <regex>
#include <sstream>

std::regex PATTERN_RXCY("^R([0-9]+)C([0-9]+)$");
std::regex PATTERN_COLROW("^([A-Z]+)([0-9]+)$");

std::string numToCol(int n)
{
    std::string res;
    while (n > 0)
    {
        res = char((n - 1) % 26 + 65) + res;
        n = (n - 1) / 26;
    }
    return res;
}

int colToNum(std::string s)
{
    int res = 0;
    for (char c : s)
    {
        res *= 26;
        res += c - 'A' + 1;
    }
    return res;
}

std::string rxcyToColrow(std::string s)
{
    std::smatch matches;

    std::regex_search(s, matches, PATTERN_RXCY);

    std::stringstream ss;
    ss << numToCol(std::stoi(matches[2].str())) << matches[1];

    return ss.str();
}

std::string colrowToRxcy(std::string s)
{
    std::smatch matches;
    std::regex_search(s, matches, PATTERN_COLROW);
    std::stringstream ss;
    ss << 'R' << matches[2] << 'C' << colToNum(matches[1]);
    return ss.str();
}

int main()
{
    int n;
    std::cin >> n;
    std::cin.ignore();

    std::string line;

    for (int i = 0; i < n; ++i)
    {
        std::getline(std::cin, line);

        if (std::regex_match(line, PATTERN_RXCY))
        {
            std::cout << rxcyToColrow(line) << std::endl;
        }
        else
        {
            std::cout << colrowToRxcy(line) << std::endl;
        }
    }
    return 0;
}
