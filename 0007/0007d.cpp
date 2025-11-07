#include <algorithm>
#include <iostream>
#include <string>

// nums
using ll = long long;
using ull = unsigned long long;

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

// const ll MOD = 998244353;
constexpr ull BASE = 179ULL;

const int MAX_N = 5000005;

ull dp[MAX_N];
ull pows[MAX_N];
ull fwd_hsh[MAX_N];
ull rev_hsh[MAX_N];

inline ull get_hash(const ull* __restrict h, const ull* __restrict pw, size_t l, size_t r) {
    return h[r] - h[l - 1] * pw[r - l + 1];
}

int main()
{
    std::string s;
    std::cin >> s;

    std::string rev_s = s;
    std::reverse(rev_s.begin(), rev_s.end());

    size_t n = s.size();    

    pows[0] = 1;
    fwd_hsh[0] = 0;
    rev_hsh[0] = 0;

    for (size_t i = 1; i < n + 1; i++)
        pows[i] = pows[i - 1] * BASE;
    for (size_t i = 1; i < n + 1; i++)
        fwd_hsh[i] = fwd_hsh[i - 1] * BASE + (unsigned char)s[i - 1];
    for (size_t i = 1; i < n + 1; i++)
        rev_hsh[i] = rev_hsh[i - 1] * BASE + (unsigned char)rev_s[i - 1];

    dp[1] = 1;
    ull res = 1;
    for (size_t i = 2; i < n + 1; i++)
    {
        if (get_hash(fwd_hsh, pows, 1, i >> 1) == get_hash(rev_hsh, pows, n - i + 1, n - i + (i >> 1)))
            dp[i] = dp[i >> 1] + 1;
        res += dp[i];
    }

    std::cout << res << std::endl;

    return 0;
}
