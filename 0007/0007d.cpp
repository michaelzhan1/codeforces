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

const ll MOD = 998244353;
const ll BASE = 233;

const int MAX_N = 5000005;
int dp[MAX_N];

ll pows[MAX_N];
ll fwd_hsh[MAX_N];
ll rev_hsh[MAX_N];

inline ll hash(ll hsh[], size_t l, size_t r)
{
    return (hsh[r] - hsh[l - 1] * pows[r - l + 1] % MOD + MOD) % MOD;
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
        pows[i] = pows[i - 1] * BASE % MOD;
    for (size_t i = 1; i < n + 1; i++)
        fwd_hsh[i] = (fwd_hsh[i - 1] * BASE % MOD + s[i - 1]) % MOD;
    for (size_t i = 1; i < n + 1; i++)
        rev_hsh[i] = (rev_hsh[i - 1] * BASE % MOD + rev_s[i - 1]) % MOD;

    dp[1] = 1;
    ll res = 1;
    for (size_t i = 2; i < n + 1; i++)
    {
        if (hash(fwd_hsh, 1, i / 2) == hash(rev_hsh, n - i + 1, n - i + i / 2))
            dp[i] = dp[i / 2] + 1;
        res += dp[i];
    }

    std::cout << res << std::endl;

    return 0;
}
