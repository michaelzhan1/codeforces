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
    vi sides(4);
    for (size_t i = 0; i < 4; i++)
        std::cin >> sides[i];
    
    std::sort(sides.begin(), sides.end());

    bool tri = false, seg = false;
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = i + 1; j < 4; j++)
        {
            for (size_t k = j + 1; k < 4; k++)
            {
                int a = sides[i];
                int b = sides[j];
                int c = sides[k];

                if (a + b > c && a + c > b && b + c > a)
                    tri = true;
                else if (a + b == c || a + c == b || b + c == a)
                    seg = true;
            }
        }
    }

    if (tri)
        std::cout << "TRIANGLE" << std::endl;
    else if (seg)
        std::cout << "SEGMENT" << std::endl;
    else
        std::cout << "IMPOSSIBLE" << std::endl;
    return 0;
}
