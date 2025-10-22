#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>

// nums
using ll = long long;

// vectors
using vi = std::vector<int>;
using vvi = std::vector<vi>;

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
const size_t LINES[8][3] = {
    {0, 1, 2},
    {3, 4, 5},
    {6, 7, 8},
    {0, 3, 6},
    {1, 4, 7},
    {2, 5, 8},
    {0, 4, 8},
    {2, 4, 6},
};

int main()
{
    std::string line;
    std::unordered_set<size_t> xs;
    std::unordered_set<size_t> os;
    for (size_t i = 0; i < 3; ++i)
    {
        std::getline(std::cin, line);
        for (size_t j = 0; j < 3; ++j)
        {
            if (line[j] == 'X')
                xs.insert(i * 3 + j);
            else if (line[j] == '0')
                os.insert(i * 3 + j);
        }
    }

    // illegal if there are too many Os or Xs
    if (xs.size() < os.size() || xs.size() >= os.size() + 2)
    {
        std::cout << "illegal" << std::endl;
        return 0;
    }

    // count the lines
    std::unordered_set<size_t> x_line;
    std::unordered_set<size_t> o_line;
    size_t x_count = 0, o_count = 0;
    for (const auto &[a, b, c] : LINES)
    {
        if (xs.find(a) != xs.end() && xs.find(b) != xs.end() && xs.find(c) != xs.end())
        {
            x_count++;
            x_line.insert(a);
            x_line.insert(b);
            x_line.insert(c);
        }
        if (os.find(a) != os.end() && os.find(b) != os.end() && os.find(c) != os.end())
        {
            o_count++;
            o_line.insert(a);
            o_line.insert(b);
            o_line.insert(c);
        }
    }

    if (x_count * o_count >= 1)
    {
        std::cout << "illegal" << std::endl;
        return 0;
    }

    if (x_count > 0)
    {
        if (x_line.size() + x_count - 1 == x_count * 3 && xs.size() > os.size())
            std::cout << "the first player won" << std::endl;
        else
            std::cout << "illegal" << std::endl;
        return 0;
    }

    if (o_count > 0)
    {
        if (o_line.size() + o_count - 1 == o_count * 3 && xs.size() == os.size())
            std::cout << "the second player won" << std::endl;
        else
            std::cout << "illegal" << std::endl;
        return 0;
    }

    if (xs.size() + os.size() == 9)
        std::cout << "draw" << std::endl;
    else if (xs.size() > os.size())
        std::cout << "second" << std::endl;
    else
        std::cout << "first" << std::endl;

    return 0;
}
