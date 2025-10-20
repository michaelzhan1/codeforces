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

    int n1 = int(ones.size());
    int n2 = int(twos.size());

    int i = n1 - 1;
    int j = n2 - 1;

    ll res = 0;
    std::vector<size_t> idxs;

    if (v % 2 == 1 && i >= 0)
    {
        size_t ii = size_t(i);
        res += ones[ii].first;
        idxs.push_back(ones[ii].second);
        i--;
        v--;
    }

    if (v == 1 && i < 0)
    {
        std::cout << 0 << std::endl;
        return 0;
    }

    // while we still have space and we still have something to choose from
    while (v > 0 && (i >= 0 || j >= 0))
    {
        size_t ii = size_t(i);
        size_t jj = size_t(j);

        // if only twos are left, take twos
        if (i < 0)
        {
            res += twos[jj].first;
            idxs.push_back(twos[jj].second);
            j--;
            v -= 2;
        }
        // else if only ones are left, takes ones
        else if (j < 0)
        {
            res += ones[ii].first;
            idxs.push_back(ones[ii].second);
            i--;
            v--;
        }
        // else if only 1x one is left but it's good, compare
        else if (i == 0)
        {
            if (ones[ii].first > twos[jj].first)
            {
                res += ones[ii].first;
                idxs.push_back(ones[ii].second);
                i--;
                v--;
            }
            else
            {
                res += twos[jj].first;
                idxs.push_back(twos[jj].second);
                j--;
                v -= 2;
            }
        }
        // else both have full options, compare
        else
        {
            if (ones[ii].first + ones[ii - 1].first > twos[jj].first)
            {
                res += ones[ii].first + ones[ii - 1].first;
                idxs.push_back(ones[ii].second);
                idxs.push_back(ones[ii - 1].second);
                i -= 2;
                v -= 2;
            }
            else
            {
                res += twos[jj].first;
                idxs.push_back(twos[jj].second);
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
