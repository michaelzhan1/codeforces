#include <algorithm>
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
    std::string line;
    std::cin >> line;

    ll open_count = 0;
    ll res = 0;
    ll open_cost, close_cost;

    std::priority_queue<std::pair<ll, size_t>> heap; // {value gain by swapping, index to swap}

    for (size_t i = 0; i < line.size(); ++i)
    {
        if (line[i] == '(')
            open_count++;
        else if (line[i] == ')')
            open_count--;
        else
        {
            std::cin >> open_cost >> close_cost;
            line[i] = ')';
            res += close_cost;
            open_count--;
            heap.push(mp(close_cost - open_cost, i));
        }

        if (open_count < 0)
        {
            if (heap.empty())
                break;
            
            std::pair<ll, size_t> replace = heap.top();
            heap.pop();

            open_count += 2;
            res -= replace.first;
            line[replace.second] = '(';
        }
    }

    if (open_count != 0)
    {
        std::cout << -1 << std::endl;
    }
    else
    {
        std::cout << res << std::endl;
        std::cout << line << std::endl;
    }

    return 0;
}
