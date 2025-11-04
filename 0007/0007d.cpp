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
std::vector<size_t> manacher(std::string orig) {
    std::string s = "#";
    for (size_t i = 0; i < orig.size(); i++)
    {
        s += orig[i];
        s += '#';
    }

    size_t n = s.size();
    std::vector<size_t> dp(n, 0); // radii
    size_t c = 0; // current umbrella palindrome center
    size_t r = 0; // right boundary of current umbrella center
    
    for (size_t i = 0; i < n; i++)
    {
        // mirror = center - (i - center)
        size_t m = 2 * c - i;

        // if mirrored palindrome is entirely contained, take dp result and short circuit
        if (i + dp[m] < r)
        {
            dp[i] = dp[m];
            continue;
        }

        // if current palindrome at i is still within the umbrella, then it must be pushing the boundary
        // based on an invariant below, i will never be more than right, only at most equal.
        if (i < r)
            dp[i] = r - i;
        
        // expand the palindrome about i. this happens when the palindrome around i exceeds the right boundary
        // so basically, we are building a new umbrella
        while (i - dp[i] > 0 && i + dp[i] < n - 1 && s[i - dp[i] - 1] == s[i + dp[i] + 1])
            dp[i]++;
        
        // if we did expand past right, then this is our new umbrella
        if (i + dp[i] > r)
        {
            c = i;
            r = i + dp[i];
        }
    }
    return dp;
}

int main()
{
    std::string s;
    std::cin >> s;

    std::vector<size_t> radii = manacher(s);
    
    // need to then take manacher output and compile res
    return 0;
}
