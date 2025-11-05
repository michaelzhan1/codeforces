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

// https://ksmeow.moe/pd-cf7d-sol/
int main()
{
    std::string s;
    std::cin >> s;

    const ll mod = 1'000'000'007; // 10**9 + 7
    const ll base = 91138233;

    ll h = 0;
    ll rh = 0;
    ll pow = 1;

    std::unordered_map<size_t, ll> freq;
    ll res = 0;

    for (size_t i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        h = (h * base + ch) % mod;
        rh = (rh + ch * pow) % mod;
        if (h == rh)
        {
            freq[i] = 1 + freq[(i - 1) / 2];
            res += freq[i];
        }
        pow = (pow * base) % mod;
    }

    std::cout << res << std::endl;
    

    return 0;
}
