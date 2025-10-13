#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>

int main()
{
    std::vector<std::string> nums;

    std::string token;
    while (std::getline(std::cin, token, '+'))
    {
        std::string s(1, token[0]);
        nums.push_back(s);
    }

    std::sort(nums.begin(), nums.end());
    std::string res = std::accumulate(
        std::next(nums.begin()),
        nums.end(),
        nums[0],
        [&](const std::string &a, const std::string &b)
        {
            return a + '+' + b;
        });
    std::cout << res << std::endl;
    return 0;
}
