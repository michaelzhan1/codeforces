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
    size_t n;
    std::cin >> n;

    vi arr(n);
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    size_t i = 0, j = arr.size() - 1;
    ll a = 0, b = 0;
    ll a_rem = arr[i], b_rem = arr[j];

    while (i < j)
    {
        // both finish eating at the same time
        if (a_rem == b_rem)
        {
            a++;
            b++;

            i++;
            j--;

            if (i <= j)
            {
                a_rem = arr[i];
                b_rem = arr[j];
            }
            else
            {
                a_rem = 0;
                b_rem = 0;
            }
        }
        // alice finishes first
        else if (a_rem < b_rem)
        {
            a++;
            i++;
            b_rem -= a_rem;
            a_rem = arr[i];
        }
        // bob finishes first
        else
        {
            b++;
            j--;
            a_rem -= b_rem;
            b_rem =arr[j];
        }
    }

    if (a_rem <= b_rem && a_rem > 0 && b_rem > 0)
        a++;
    else if (a_rem > b_rem)
        b++;
    
    std::cout << a << ' ' << b << std::endl;

    return 0;
}
