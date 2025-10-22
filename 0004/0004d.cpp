#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
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
    int n, w, h;
    std::cin >> n >> w >> h;

    std::vector<std::array<int, 3>> dims;
    int e_w, e_h;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> e_w >> e_h;
        if (e_w > w && e_h > h)
            dims.push_back({e_w, e_h, i + 1});
    }
    if (dims.size() == 0)
    {
        std::cout << 0 << std::endl;
        return 0;
    }

    std::sort(dims.begin(), dims.end());

    vi dp(dims.size(), 1);
    std::vector<int> prev(dims.size(), -1);

    for (size_t i = 0; i < dp.size(); i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            if (dims[i][0] > dims[j][0] && dims[i][1] > dims[j][1])
            {
                if (dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    prev[i] = int(j);
                }
            }
        }
    }

    int max_i = int(std::distance(dp.begin(), std::max_element(dp.begin(), dp.end())));
    std::vector<int> path;

    while (max_i >= 0)
    {
        path.push_back(dims[size_t(max_i)][2]);
        max_i = prev[size_t(max_i)];
    }

    std::reverse(path.begin(), path.end());

    std::cout << path.size() << std::endl;
    for (size_t i = 0; i < path.size(); i++)
    {
        if (i > 0)
            std::cout << ' ';
        std::cout << path[i];
    }

    std::cout << std::endl;

    return 0;
}
