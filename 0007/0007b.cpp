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
using pss = std::pair<size_t, size_t>;

int main()
{
    size_t t, m;
    std::cin >> t >> m;

    std::vector<pss> free{mp(0, m)};       // {start_i, width}
    std::unordered_map<uint, pss> loc_map; // id -> {start_i, width}
    uint id = 1;

    std::string cmd;
    size_t alloc_arg;
    uint erase_arg;
    bool found;

    for (size_t i = 0; i < t; i++)
    {
        std::cin >> cmd;

        if (cmd == "alloc")
        {
            std::cin >> alloc_arg;
            found = false;
            for (size_t j = 0; j < free.size(); j++)
            {
                pss &range = free[j];
                if (alloc_arg == range.second) // fits exactly, no longer free
                {
                    free.erase(free.begin() + static_cast<std::ptrdiff_t>(j));
                    found = true;
                    loc_map[id] = mp(range.first, alloc_arg);
                    break;
                }
                else if (alloc_arg < range.second) // fits within, update range
                {
                    loc_map[id] = mp(range.first, alloc_arg);
                    range.first += alloc_arg;
                    range.second -= alloc_arg;
                    found = true;
                    break;
                }
            }

            if (found)
            {
                std::cout << id << std::endl;
                id++;
            }
            else
            {
                std::cout << "NULL" << std::endl;
            }
        }
        else if (cmd == "erase")
        {
            std::cin >> erase_arg;

            // id doesn't exist
            if (loc_map.find(erase_arg) == loc_map.end())
            {
                std::cout << "ILLEGAL_ERASE_ARGUMENT" << std::endl;
                continue;
            }

            // find and pop range
            pss block = loc_map[erase_arg];
            auto it = std::lower_bound(free.begin(), free.end(), block);
            std::cout << it->first << ' ' << it->second << std::endl;
            it = free.insert(it, block); // bring to inserted block
            loc_map.erase(erase_arg);

            // if not at the end, try to merge right
            if (std::next(it) != free.end())
            {
                const auto &next = std::next(it);
                if (it->first + it->second == next->first)
                {
                    it->second += next->second;
                    free.erase(next);
                }
            }

            // if not at beginning, try to merge left
            if (it != free.begin())
            {
                const auto &prev = std::prev(it);
                if (prev->first + prev->second == it->first)
                {
                    prev->second += it->second;
                    free.erase(it);
                }
            }
        }
        else
        {
        }

        std::cout << cmd << '\n'
                  << std::endl;
        std::cout << "free" << std::endl;
        for (auto p : free)
        {
            std::cout << p.first << ' ' << p.second << std::endl;
        }

        std::cout << '\n'
                  << "used" << std::endl;
        for (auto it : loc_map)
        {
            std::cout << it.first << " (" << it.second.first << ' ' << it.second.second << ')' << std::endl;
        }
        std::cout << "=============" << std::endl;
    }

    return 0;
}
