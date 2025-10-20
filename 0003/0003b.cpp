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

int main()
{
    size_t n, v;
    std::cin >> n >> v;

    std::vector<std::pair<int, size_t>> ones;
    std::vector<std::pair<int, size_t>> twos;

    int wt;
    ll val;
    for (size_t i = 0; i < n; ++i)
    {
        std::cin >> wt >> val;
        if (wt == 1)
            ones.push_back(mp(val, i + 1));
        else
            twos.push_back(mp(val, i + 1));
    }

    std::sort(ones.begin(), ones.end());
    std::sort(twos.begin(), twos.end());

    for (auto p : ones)
    {
        std::cout << p.first << ' ' << p.second << std::endl;
    }
    std::cout << std::endl;
    for (auto p : twos)
        std::cout << p.first << ' ' << p.second << std::endl;

    int n1 = int(ones.size());
    int n2 = int(twos.size());

    int i = n1 - 1;
    int j = n2 - 1;

    ll res = 0;
    std::vector<size_t> idxs;

    // while we still have space and we still have something to choose from
    while (v > 0 && (i >= 0 || j >= 0))
    {
        size_t i_size_t = size_t(i);
        size_t j_size_t = size_t(j);
        // only one space left, must be kayak or nothing
        if (v == 1)
        {
            if (i >= 0)
            {
                res += ones[i_size_t].first;
                idxs.push_back(ones[i_size_t].second);
            }
            break;
        }

        // // three spaces left, and at least 2 kayaks and at least 1 catamaran
        // if (v == 3 && i >= 1 && j >= 0)
        // {
        //     std::cout << i << ' ' << j << std::endl;
        //     // if >= 3 kayaks and better, take all kayaks
        //     if (i >= 2 && ones[i_size_t].first + ones[i_size_t - 1].first + ones[i_size_t - 2].first > twos[j_size_t].first)
        //     {
        //         res += ones[i_size_t].first + ones[i_size_t - 1].first + ones[i_size_t - 2].first;
        //         idxs.push_back(ones[i_size_t].second);
        //         idxs.push_back(ones[i_size_t - 1].second);
        //         idxs.push_back(ones[i_size_t - 2].second);
        //     }
        //     // else if it's worth taking both kayaks, do that
        //     else if (ones[i_size_t - 1].first > twos[j_size_t].first)
        //     {
        //         res += ones[i_size_t].first + ones[i_size_t - 1].first;
        //         idxs.push_back(ones[i_size_t].second);
        //         idxs.push_back(ones[i_size_t - 1].second);
        //     }
        //     // else, take catamaran and kayak
        //     else
        //     {
        //         res += ones[i_size_t].first + twos[j_size_t].first;
        //         idxs.push_back(ones[i_size_t].second);
        //         idxs.push_back(twos[j_size_t].second);
        //     }
        //     break;
        // }

        // if only twos are left, take twos
        if (i < 0)
        {
            res += twos[j_size_t].first;
            idxs.push_back(twos[j_size_t].second);
            j--;
            v -= 2;
        }
        // else if only ones are left, takes ones
        else if (j < 0)
        {
            res += ones[i_size_t].first;
            idxs.push_back(ones[i_size_t].second);
            i--;
            v--;
        }
        // else if only 1x one is left, compare
        else if (i == 0)
        {
            if (ones[i_size_t].first > twos[j_size_t].first)
            {
                res += ones[i_size_t].first;
                idxs.push_back(ones[i_size_t].second);
                i--;
                v--;
            }
            else
            {
                res += twos[j_size_t].first;
                idxs.push_back(twos[j_size_t].second);
                j--;
                v -= 2;
            }
        }
        // else both have full options, compare
        else
        {
            if (ones[i_size_t].first + ones[i_size_t - 1].first > twos[j_size_t].first)
            {
                res += ones[i_size_t].first + ones[i_size_t - 1].first;
                idxs.push_back(ones[i_size_t].second);
                idxs.push_back(ones[i_size_t - 1].second);
                i -= 2;
                v -= 2;
            }
            else
            {
                res += twos[j_size_t].first;
                idxs.push_back(twos[j_size_t].second);
                j--;
                v -= 2;
            }
        }
    }

    std::cout << res << std::endl;
    for (auto it = idxs.begin(); it != idxs.end(); it++)
    {
        if (it != idxs.begin())
            std::cout << ' ';
        std::cout << *it;
    }
    std::cout << std::endl;

    return 0;
}
