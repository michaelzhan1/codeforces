#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// nums
using ll = long long;

// vectors
using vi = std::vector<int>;
using vvi = std::vector<vi>;
using vs = std::vector<size_t>;

// sets
using usi = std::unordered_set<int>;
using uss = std::unordered_set<size_t>;

// pairs
template <typename T1, typename T2>
inline std::pair<T1, T2> mp(T1 a, T2 b)
{
    return std::make_pair(a, b);
}

// pair hashing
struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &p) const
    {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;
    }
};

// problem specific

int main()
{
    std::string line;
    std::vector<std::string> lines;

    size_t max_len = 0;
    while (std::getline(std::cin, line))
    {
        lines.push_back(line);
        max_len = std::max(max_len, line.size());
    }
    size_t width = max_len + 2;

    // top
    std::cout << std::string(width, '*') << std::endl;

    bool tie_left = false;
    size_t gap;
    for (const std::string &line : lines)
    {
        gap = (width - 2 - line.size()) / 2;
        // evenly spaced
        if ((width - line.size()) % 2 == 0)
            std::cout << '*' << std::string(gap, ' ') << line << std::string(gap, ' ') << '*' << std::endl;
        // not evenly spaced
        else
        {
            if (tie_left)
            {
                std::cout << '*' << std::string(gap + 1, ' ') << line << std::string(gap, ' ') << '*' << std::endl;
            }
            else
            {
                std::cout << '*' << std::string(gap, ' ') << line << std::string(gap + 1, ' ') << '*' << std::endl;
            }
            tie_left = !tie_left;
        }
    }

    // bottom
    std::cout << std::string(width, '*') << std::endl;
    return 0;
}
