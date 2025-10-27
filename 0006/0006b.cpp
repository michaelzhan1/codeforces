#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <queue>
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
    size_t n, m;
    char color;
    std::cin >> n >> m >> color;
    
    
    std::vector<std::string> lines(n);
    std::unordered_set<size_t> idxs;
    for (size_t i = 0; i < n; ++i)
    {
        std::cin >> lines[i];
        for (size_t j = 0; j < m; ++j)
        {
            if (lines[i][j] == color)
                idxs.insert(i * m + j);
        }
    }

    std::unordered_set<char> colors{color};    
    
    
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            size_t idx = i * m + j;
            if (
                lines[i][j] != '.' &&
                ((i >= 1 && idxs.find(idx - m) != idxs.end()) ||
                (i <= n - 2 && idxs.find(idx + m) != idxs.end()) ||
                (j >= 1 && idxs.find(idx - 1) != idxs.end()) ||
                (j <= m - 2 && idxs.find(idx + 1) != idxs.end()))
            )
            {
                colors.insert(lines[i][j]);
            }
        }
    }

    std::cout << colors.size() - 1 << std::endl;

    return 0;
}
